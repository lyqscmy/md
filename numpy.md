# data type
[](https://docs.scipy.org/doc/numpy-1.13.0/user/basics.types.html)

xb = np.random.random((nb, d)).astype('float32')
xb[:, 0] += np.arange(nb) / 1000.

[](https://docs.scipy.org/doc/numpy-1.13.0/reference/arrays.dtypes.html)

```shell
>>> dt = np.dtype('i4')   # 32-bit signed integer
>>> dt = np.dtype('f8')   # 64-bit floating-point number
>>> dt = np.dtype('c16')  # 128-bit complex floating-point number
>>> dt = np.dtype('a25')  # 25-length zero-terminated bytes
>>> dt = np.dtype('U25')  # 25-character string
```

# matrix product