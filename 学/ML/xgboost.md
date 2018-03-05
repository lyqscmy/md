# diff
- Booster.java
- XGBoostJNI.java
- xgboost4j.h/xgboost4j.cpp
- c_api.h/c_api.cc

- learner.cc/learner.cc
- gbtree.cc
- predictor.h/cpu_predictor.cpp
    vivo_predictleaf



# TODO
二进制格式兼容加载模型
提取所需信息



[xgboost官方文档](https://xgboost.readthedocs.io/en/latest/model.html)

[阿里杨军讲技术实现细节](https://www.zhihu.com/question/41354392/answer/124274741)

# predictor
```cpp
bst_float PredValue(const RowBatch::Inst& inst,
                             const std::vector<std::unique_ptr<RegTree>>& trees,
                             const std::vector<int>& tree_info, int bst_group,
                             unsigned root_index, RegTree::FVec* p_feats,
                             unsigned tree_begin, unsigned tree_end);
```

# feat
```cpp
feat.fvalue(split_index);
feat.is_missing(split_index);
```

# Node
```cpp
is_leaf();
split_index();
split_cond();
cdefault();
cleft();
cright();
leaf_value();
```

# tree_model.h

```cpp
int RegTree::GetLeafIndex(const RegTree::FVec& feat, unsigned root_id);
int GetNext(pid, feat.fvalue(split_index), feat.is_missing(split_index));
```