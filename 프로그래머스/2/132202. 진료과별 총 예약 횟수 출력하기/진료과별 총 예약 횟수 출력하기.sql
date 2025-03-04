select mcdp_cd as 진료과코드, count(1) as 5월예약건수
from appointment
where date_format(apnt_ymd, '%Y-%m') = '2022-05'
group by mcdp_cd
order by 2 asc, 1 asc
-- order by count(1) asc, mcdp_cd asc