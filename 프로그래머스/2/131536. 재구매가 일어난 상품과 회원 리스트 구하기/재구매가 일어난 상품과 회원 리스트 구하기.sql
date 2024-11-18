-- 코드를 입력하세요
SELECT DISTINCT os1.user_id, os1.product_id
FROM online_sale AS os1 
	JOIN online_sale AS os2 
    ON os1.user_id = os2.user_id
    AND os1.product_id = os2.product_id
WHERE os1.online_sale_id <> os2.online_sale_id
ORDER BY os1.user_id ASC, os1.product_id DESC;