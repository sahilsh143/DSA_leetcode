# Write your MySQL query statement below
Select Customers.name as Customers
from Customers
left join Orders
on Customers.id=orders.customerId
WHERE Orders.customerId IS NULL;
