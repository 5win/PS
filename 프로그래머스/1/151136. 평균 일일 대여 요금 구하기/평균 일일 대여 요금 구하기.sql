-- 코드를 입력하세요
SELECT ROUND(SUM(DAILY_FEE) / COUNT(*))
FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE='SUV';