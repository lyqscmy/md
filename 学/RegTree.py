# micro benchmark
# feat(indices, values)

# 多线程共用
class TreeModel(object):
    trees = []

    def __init__(self, bytearray):
        pass
    
    def predictValueInst(self, feat):
        preds = []
        for tree in self.trees:
            tid = tree.get_leaf_index(feat)
            value = tree.get_value(tid)
            preds.append(value)
        return preds

    def predictLeafInst(self, feat):
        preds = []
        for tree in self.trees:
            tid = tree.get_leaf_index(feat)
            preds.append(tid)
        return preds

class RegTree(object):
    default = None
    left = None
    right = None
    is_leaf = False

    tid = None
    split_index = None
    split_cond = None

    def get_value(self, tid):
        pass

    def get_leaf_index(self, feat):
        node = self
        tid = self.tid
        split_index = self.split_index
        while not node.is_leaf:
            tid = node.get_next(feat.fvalue(split_index), feat.is_missing(split_index))
        return tid
    # inline
    def get_next(self, fvalue, is_missing):
        if is_missing:
            return self.default
        elif fvalue < self.split_cond
            return self.left
        else:
            return self.right

class RegTree(object):
    # why node array not link tree?
    node = []
    # inline
    def get_leaf_index(self, feat):
        pid = 0
        while not self.node[pid].is_leaf:
            split_index = self.node[pid].split_index
            pid = self.get_next(pid, feat.fvalue(split_index), feat.is_missing(split_index))
            return pid
    # inline
    def get_next(self, pid, fvalue, is_missing):
        split_value = self.node[pid].split_cond
        if is_missing:
            return self.node[pid].cdefault
        elif fvalue < split_value
            return self.node[pid].cleft
        else:
            return self.node[pid].cright

class Node(object):
    leaf_value = None
    split_cond = None
    # split feature index, left split or right split depends on the highest bit
    sindex = None
    left = None
    right = None