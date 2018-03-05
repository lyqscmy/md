cmake .. -DUSE_OPENMP:BOOL=ON -DPLUGIN_UPDATER_GPU:BOOL=OFF -DUSE_AZURE:BOOL=OFF -DUSE_HDFS:BOOL=OFF -DJVM_BINDINGS:BOOL=ON
# DMatrix
## 预测阶段如何使用？
- MetaInfo
- DataIter<DType>
- RowBatch
- SimpleCSRSource

```cpp
const MetaInfo& info = p_fmat->info();
dmlc::DataIter<RowBatch>* iter = p_fmat->RowIterator();
```

```cpp
 itr->BeforeFirst();
 while (itr->Next()) {
    const DType &batch = itr->Value();
    // some computations
 }
```
## 如何创建？

## handle

```cpp
DMatrixHandle result;
jint ret = (jint) XGDMatrixCreateFromCSREx((size_t const *)indptr, (unsigned int const *)indices, (float const *)data, nindptr, nelem, jcol, &result);
XGB_DLL int XGDMatrixCreateFromCSREx(const size_t* indptr,
                                     const unsigned* indices,
                                     const bst_float* data,
                                     size_t nindptr,
                                     size_t nelem,
                                     size_t num_col,
                                     DMatrixHandle* out)
*out  = new std::shared_ptr<DMatrix>(DMatrix::Create(std::move(source)));

XGB_DLL int XGBoosterPredict(BoosterHandle handle,
                             DMatrixHandle dmat,
                             int option_mask,
                             unsigned ntree_limit,
                             xgboost::bst_ulong *len,
                             const bst_float **out_result)

Booster *bst = static_cast<Booster*>(handle);
```