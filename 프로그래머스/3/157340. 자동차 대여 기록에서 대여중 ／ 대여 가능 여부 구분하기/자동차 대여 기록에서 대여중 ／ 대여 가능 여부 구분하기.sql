-- 코드를 입력하세요

select a.car_id, case 
					when a.car_id in (select b.car_id 
                                     from car_rental_company_rental_history as b
                                     where b.start_date <= '2022-10-16' and '2022-10-16' <= b.end_date)
                    then '대여중'
                    else '대여 가능'
                 end as 'availability'
from car_rental_company_rental_history as a
group by a.car_id
order by a.car_id desc;