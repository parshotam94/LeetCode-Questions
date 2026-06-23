# Write your MySQL query statement below
select uni.unique_id, e.name
from Employees e
Left join EmployeeUNI uni
On e.id=uni.id;
