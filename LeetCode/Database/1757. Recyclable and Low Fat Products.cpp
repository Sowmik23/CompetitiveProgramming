// 1757. Recyclable and Low Fat Products


/* Write your PL/SQL query statement below */

select product_id
from Products
where low_fats = 'Y' and recyclable = 'Y';
