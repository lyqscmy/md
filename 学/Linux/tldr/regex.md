# books
[Mastering Regular Expressions 3rd](https://book.douban.com/subject/1872091/)

# sites
* [Unicode Character Ranges](http://jrgraphix.net/research/unicode.php)
* [Python unicode cheatsheet](https://www.pythonsheets.com/notes/python-unicode.html)
* [Python re](https://docs.python.org/3/library/re.html)

# Python
* 过滤汉字
```python
pattern =   r'(?:[\u0020-\u007F\u3400-\u4dbf\u4e00-\u9fff\uf900-\ufaff])'
def make_filter(pattern):
    import re
    prog = re.compile(pattern)
    return lambda string : ''.join([c for c in string if prog.match(c)])

f = make_filter(pattern)
```

```python
def get_code_point(s):
    for _c in s: print('U+%04x' % ord(_c))
```