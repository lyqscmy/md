tag:python|log
# sites
[tutorial](https://docs.python.org/3/tutorial/index.html)

# book
[fluent python](https://book.douban.com/subject/26278021/)

# profile
# debug
ipython
# closures
- 定义
  A closure is function with an extended scope that encompasses non-global
  variables referenced in the body of the function but not defined there.

- 坑点
  with immutable types like numbers, strings, tuples etc., all you can is read, but never
  update. If you try to rebind them, as in count = count + 1, then you are implicitly
  creating a local variable count. It is no longer a free variable, therefore it is not saved in
  the closure.

# [data model](https://docs.python.org/3/reference/datamodel.html)
## immutable types
- number
- string
- tuple

# [re](https://docs.python.org/3/library/re.html)

```python
import re
prog = re.compile(pattern)
result = prog.match(string)
```

过滤汉字

```python
# 有拼音的汉字
if SUPPORT_UCS4:
    RE_HANS = re.compile(
        r'^(?:['
        r'\u3400-\u4dbf'           # CJK扩展A:[3400-4DBF]
        r'\u4e00-\u9fff'           # CJK基本:[4E00-9FFF]
        r'\uf900-\ufaff'           # CJK兼容:[F900-FAFF]
        r'\U00020000-\U0002A6DF'   # CJK扩展B:[20000-2A6DF]
        r'\U0002A703-\U0002B73F'   # CJK扩展C:[2A700-2B73F]
        r'\U0002B740-\U0002B81D'   # CJK扩展D:[2B740-2B81D]
        r'\U0002F80A-\U0002FA1F'   # CJK兼容扩展:[2F800-2FA1F]
        r'])+$'
    )
else:
    RE_HANS = re.compile(
        r'^(?:['
        r'\u3400-\u4dbf'           # CJK扩展A:[3400-4DBF]
        r'\u4e00-\u9fff'           # CJK基本:[4E00-9FFF]
        r'\uf900-\ufaff'           # CJK兼容:[F900-FAFF]
        r'])+$'
    )
```

```python
pattren =   r'^(?:[\u3400-\u4dbf\u4e00-\u9fff\uf900-\ufaff])+$'
def make_filter(pattern):
    prog = re.compile(pattern)
    return lambda string : ''.join([c for c in string if prog.match(c)])
```

```python
def split(xs, validation = [0.7,0.2,0.1]):
    from random import shuffle
    shuffle(xs)
    size = len(xs)
    index = (int(size*validation[0]), int(size*(validation[0]+validation[1])))
    train, val, test = xs[0:index[0]], xs[index[0]:index[1]], xs[index[1]:-1]
    return train,val, test
```

# awesome idea
- [pangu](https://github.com/vinta/pangu.py)
```python
pangu.spacing('新八的構造成分有95%是眼鏡、3%是水、2%是垃圾')
# output: u'新八的構造成分有 95% 是眼鏡、3% 是水、2% 是垃圾'

pangu.spacing_text("Mr.龍島主道：「Let's Party!各位高明博雅君子！」")
# output: u"Mr. 龍島主道：「Let's Party! 各位高明博雅君子！」"
```
# [csv](http://devdocs.io/python~3.6/library/csv#csv.Sniffer)

* write
```python
with open('example.csv', 'w') as csvfile:
    writer = csv.writer(csvfile, dialect)
    writer.writerrows(xs)
```

* read
```python
>>> import csv
>>> with open('eggs.csv', newline='') as csvfile:
...     spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
...     for row in spamreader:
...         print(', '.join(row))
```

- 检测未知csv的dialect
``` python
with open('example.csv') as csvfile:
    dialect = csv.Sniffer().sniff(csvfile.read(1024))
    csvfile.seek(0)
    reader = csv.reader(csvfile, dialect)
    # ... process CSV file contents here ...
```

# list

- del element
  list.index(x[, start[, end]])

# [sqlite3](https://docs.python.org/3.6/library/sqlite3.html)


```python
import sqlite3
conn = sqlite3.connect('./data/news.db')
conn.execute("SELECT channel_1th, title FROM news")

c = conn.cursor()
c.execute("SELECT * FROM news limit 5")
# Never do this -- insecure!
symbol = 'RHAT'
c.execute("SELECT * FROM stocks WHERE symbol = '%s'" % symbol)

# Do this instead
t = ('RHAT',)
c.execute('SELECT * FROM stocks WHERE symbol=?', t)
print(c.fetchone())

# Larger example that inserts many records at a time
purchases = [('2006-03-28', 'BUY', 'IBM', 1000, 45.00),
             ('2006-04-05', 'BUY', 'MSFT', 1000, 72.00),
             ('2006-04-06', 'SELL', 'IBM', 500, 53.00),
            ]
c.executemany('INSERT INTO stocks VALUES (?,?,?,?,?)', purchases)
```

# [requests](http://docs.python-requests.org/en/master/)
```python
>>> r = requests.get('https://api.github.com/user', auth=('user', 'pass'))
>>> r.status_code
200
>>> r.headers['content-type']
'application/json; charset=utf8'
>>> r.encoding
'utf-8'
>>> r.text
u'{"type":"User"...'
>>> r.json()
{u'private_gists': 419, u'total_private_repos': 77, ...}
```


# pathlib
[迭代文件夹](http://devdocs.io/python~3.6/library/pathlib#pathlib.Path.iterdir)
```shell
>>> p = Path('docs')
>>> for child in p.iterdir(): child
>>> ...
>>> PosixPath('docs/conf.py')
>>> PosixPath('docs/_templates')
>>> PosixPath('docs/make.bat')
>>> PosixPath('docs/index.rst')
>>> PosixPath('docs/_build')
>>> PosixPath('docs/_static')
>>> PosixPath('docs/Makefile')
```
Accessing individual parts
 PurePath.name
A string representing the final path component, excluding the drive and root, if any:
```shell
>>> PurePosixPath('my/library/setup.py').name
    'setup.py'
>>> p = Path('docs')
>>> for child in p.iterdir(): child
>>> ...
>>> PosixPath('docs/conf.py')
>>> PosixPath('docs/_templates')
>>> PosixPath('docs/make.bat')
>>> PosixPath('docs/index.rst')
>>> PosixPath('docs/_build')
>>> PosixPath('docs/_static')
>>> PosixPath('docs/Makefile')
```
# namedtuple
作为record使用
```shell
>>> Point = namedtuple('Point', ['x', 'y'])
>>> p = Point(11, y=22)     # instantiate with positional or keyword arguments
>>> p[0] + p[1]             # indexable like the plain tuple (11, 22)
>>> 33
>>> x, y = p                # unpack like a regular tuple
>>> x, y
>>> (11, 22)
>>> p.x + p.y               # fields also accessible by name
>>> 33
>>> p                       # readable __repr__ with a name=value style
>>> Point(x=11, y=22)
```

# json

- 默认不是utf-8
```python
with open('example.json','w') as f:
    json.dump(object, f, ensure_ascii=False)
```

# defaultdict
```shell
>>> s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
>>> d = defaultdict(list)
>>> for k, v in s:
>>> ...     d[k].append(v)
>>> ...
>>> sorted(d.items())
>>> [('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]
>>> 
```

# [set](http://devdocs.io/python~3.6/library/stdtypes#set)

set - other - ...
    Return a new set with elements in the set that are not in the others.

set ^ other
    Return a new set with elements in either the set or other but not both.

# statci analysis tools
- Mypy
- Pylint
- https://github.com/google/yapf

# file
- read file by line
```python
for line in f:
    print(line, end='')
```

# [string format](https://pyformat.info/#number_padding)

# log
switch output by level
selective in the same level by what?