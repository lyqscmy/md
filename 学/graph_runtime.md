tag:TVM|graph_runtime

// The graph nodes.
std::vector<Node> nodes_;

// The argument nodes.
std::vector<uint32_t> input_nodes_;

// output entries
std::vector<NodeEntry> outputs_;

/*! \brief common storage pool */
std::vector<DLTensor*> storage_pool_;

/*! \brief data entry of each node */
std::vector<DLTensor> data_entry_;

/*! \brief operator on each node */
std::vector<std::function<void()> > op_execs_;


void SetInput(int index, DLTensor* data_in) {
    CHECK_LT(static_cast<size_t>(index), input_nodes_.size());
    uint32_t eid = this->entry_id(input_nodes_[index], 0);
    TVM_CCALL(TVMArrayCopyFromTo(data_in, &data_entry_[eid], nullptr));
}

void Run() {
    // setup the array and requirements.
    for (size_t i = 0; i < op_execs_.size(); ++i) {
        if (op_execs_[i]) op_execs_[i]();
    }
}

void GetOutput(int index, DLTensor* data_out) {
    CHECK_LT(static_cast<size_t>(index), outputs_.size());
    uint32_t eid = this->entry_id(outputs_[index]);
    TVM_CCALL(TVMArrayCopyFromTo(&data_entry_[eid], data_out, nullptr));
}