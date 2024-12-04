-- 코드를 작성해주세요

SELECT A.id,
	(CASE
    	WHEN B.rank <= C.count * 0.25 THEN 'CRITICAL'
    	WHEN C.count * 0.25 < B.rank AND B.rank <= C.count * 0.5 THEN 'HIGH'
    	WHEN C.count * 0.5 < B.rank AND B.rank <= C.count * 0.75 THEN 'MEDIUM'
     	ELSE 'LOW'
    END) AS colony_name
		
FROM ecoli_data AS A 
		JOIN (SELECT id, ROW_NUMBER() OVER (ORDER BY size_of_colony DESC) AS 'rank' FROM ecoli_data) AS B
		ON A.id = B.id,
    (SELECT COUNT(1) AS 'count' FROM ecoli_data) AS C
ORDER BY A.id ASC;