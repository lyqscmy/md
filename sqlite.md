# book
- [sql必知必会](https://book.douban.com/subject/24250054/)

- create table
```sql
CREATE TABLE news
(
    title TEXT DEFAULT '',
    content TEXT DEFAULT '',
    channel_1st TEXT DEFAULT '',
    channel_2nd TEXT DEFAULT ''
);
```
- insert
    - 插入完整的行
    - 插入行的一部分
    - 插入某些查询的结果
```sql
INSERT INTO Customers(cust_id,
                      cust_name,
                      cust_address,
                      cust_city,
                      cust_state,
                      cust_zip,
                      cust_country)
VALUES('1000000006',
        'Toy Land',
        '123 Any Street',
        'New York',
        'NY',
        '11111',
        'USA');
```
# sqlite3
[Data types](https://www.sqlite.org/datatype3.html)

## shell
sqlite example.db
.tables
.schema [tablename]

# [NULL vs DEFAULT]()