-- 코드를 작성해주세요

SELECT COUNT(A.fish_name) AS fish_count, A.fish_name
FROM fish_info AS B
	LEFT JOIN fish_name_info AS A
	ON A.fish_type = B.fish_type
GROUP BY A.fish_name
ORDER BY fish_count DESC;