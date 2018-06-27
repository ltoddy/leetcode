SELECT Customers.Name as `Customers`
FROM Customers
  LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;
