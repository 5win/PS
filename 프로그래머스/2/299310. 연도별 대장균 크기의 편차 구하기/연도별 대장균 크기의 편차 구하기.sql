-- 코드를 작성해주세요
SELECT b.year, b.max_size - a.size_of_colony AS year_dev, a.id
FROM ecoli_data AS a
	JOIN 
    	(SELECT MAX(size_of_colony) AS max_size, YEAR(differentiation_date) AS year
        FROM ecoli_data
        GROUP BY year) AS b
   	ON YEAR(a.differentiation_date) = b.year
ORDER BY year, year_dev;