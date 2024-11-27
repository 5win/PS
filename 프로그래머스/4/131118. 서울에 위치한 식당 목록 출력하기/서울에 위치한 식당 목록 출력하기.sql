-- 코드를 입력하세요
SELECT a.rest_id, a.rest_name, a.food_type, a.favorites, a.address, ROUND(AVG(b.review_score), 2) AS score
FROM rest_info AS a JOIN rest_review AS b ON a.rest_id=b.rest_id
WHERE a.address LIKE '서울%'
GROUP BY a.rest_id
ORDER BY ROUND(AVG(b.review_score), 2) DESC, a.favorites DESC;