-- SELECT * FROM dbo.Consultants1 WHERE ConsultantName LIKE 'P%'

-- SELECT * FROM dbo.Consultants1 WHERE SUBSTRING(ConsultantName, 1, CHARINDEX(' ', ConsultantName) - 1) LIKE '%ska' AND SUBSTRING(ConsultantName, CHARINDEX(' ', ConsultantName) + 1, LEN(ConsultantName)) LIKE 'M%' 

-- SELECT * FROM dbo.Consultants1 WHERE LEN(SUBSTRING(ConsultantName, CHARINDEX(' ', ConsultantName) + 1, LEN(ConsultantName))) = 5; 

-- SELECT * FROM dbo.Consultants1 WHERE LEN(SUBSTRING(ConsultantName, CHARINDEX(' ', ConsultantName) + 1, LEN(ConsultantName))) >= 5;

-- SELECT * FROM dbo.Products1 WHERE CHARINDEX(' ', ProductName) > 0

-- SELECT * FROM dbo.Products1 WHERE LEN(ProductName) - LEN(REPLACE(ProductName, ' ', '')) = 1

-- SELECT * FROM dbo.Products1 WHERE CHARINDEX('D', ProductName) > 0 OR CHARINDEX('d', ProductName) > 0

-- SELECT p.ProductName FROM dbo.Products1 p LEFT JOIN dbo.OrderDetails1 o ON p.ProductID = o.ProductID WHERE o.ProductID IS NULL

-- SELECT od.OrderID, SUM(CAST(p.ProductPrice AS DECIMAL(10,1)) * od.Quantity) AS total_amount FROM dbo.OrderDetails1 od JOIN dbo.Products1 p ON od.ProductID = p.ProductID GROUP BY od.OrderID

-- SELECT od.ProductID, COUNT(DISTINCT od.OrderID) AS order_count FROM dbo.OrderDetails1 od GROUP BY od.ProductID

-- SELECT * FROM dbo.Products1 WHERE ProductID IN (SELECT ProductID FROM dbo.OrderDetails1 GROUP BY ProductID HAVING COUNT(*) >= 2)

-- SELECT c.ConsultantID, c.ConsultantName, SUM(CONVERT(DECIMAL(10, 1), p.ProductPrice) * od.Quantity) AS total_profit FROM dbo.Consultants1 c 
-- JOIN dbo.Orders1 o ON c.ConsultantID = o.ConsultantID 
-- JOIN dbo.OrderDetails1 od ON o.OrderID = od.OrderID
-- JOIN dbo.Products1 p ON od.ProductID = p.ProductID 
-- GROUP BY c.ConsultantID, c.ConsultantName

-- SELECT AVG(total_profit) AS average_profit FROM (SELECT c.ConsultantID, SUM(CONVERT(DECIMAL(10, 2), p.ProductPrice) * od.Quantity) AS total_profit
-- FROM dbo.Consultants1 c
-- JOIN dbo.Orders1 o ON c.ConsultantID = o.ConsultantID
-- JOIN dbo.OrderDetails1 od ON o.OrderID = od.OrderID
-- JOIN dbo.Products1 p ON od.ProductID = p.ProductID
-- GROUP BY c.ConsultantID
-- ) AS consultant_profit

-- SELECT AVG(total_amount) AS average_order_amount
-- FROM (
--     SELECT o.OrderID, SUM(CONVERT(DECIMAL(10, 1), p.ProductPrice) * od.Quantity) AS total_amount
--     FROM dbo.Orders1 o
--     JOIN dbo.OrderDetails1 od ON o.OrderID = od.OrderID
--     JOIN dbo.Products1 p ON od.ProductID = p.ProductID
--     GROUP BY o.OrderID
-- ) order_amount 

-- SELECT AVG(product_count) AS average_products_per_order FROM (SELECT o.OrderID, COUNT(od.ProductID) AS product_count
-- FROM dbo.Orders1 o
-- JOIN dbo.OrderDetails1 od ON o.OrderID = od.OrderID
-- GROUP BY o.OrderID
-- ) AS order_products

-- WITH ExpensiveProduct AS (
--     SELECT TOP 1 WITH TIES
--     p.ProductID,
--     p.ProductName,
--     p.ProductPrice,
--     COUNT(DISTINCT od.OrderID) AS OrderCount,
--     COUNT(DISTINCT o.ConsultantID) AS ConsultantCount
--     FROM dbo.Products1 p
--     JOIN dbo.OrderDetails1 od ON p.ProductID = od.ProductID
--     JOIN dbo.Orders o ON od.OrderID = o.OrderID
--     GROUP BY p.ProductID, p.ProductName, p.ProductPrice
--     ORDER BY ROW_NUMBER() OVER (ORDER BY p.ProductPrice DESC)
-- )
-- SELECT
--     ep.ProductName AS ExpensiveProductName,
--     ep.ProductPrice AS ExpensiveProductPrice,
--     ep.OrderCount,
--     ep.ConsultantCount,
--     c.ConsultantName
--     FROM ExpensiveProduct ep
--     JOIN dbo.OrderDetails1 od ON ep.ProductID = od.ProductID
--     JOIN dbo.Orders1 o ON od.OrderID = o.OrderID
--     JOIN dbo.Consultants1 c ON o.ConsultantID = c.ConsultantID
