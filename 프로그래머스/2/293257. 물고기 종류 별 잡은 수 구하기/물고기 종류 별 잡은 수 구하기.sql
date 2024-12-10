-- 코드를 작성해주세요

SELECT B.fish_count, A.fish_name
FROM fish_name_info AS A
	JOIN (SELECT fish_type, COUNT(1) AS fish_count
         FROM fish_info
         GROUP BY fish_type) AS B
  	ON A.fish_type = B.fish_type
ORDER BY fish_count DESC;