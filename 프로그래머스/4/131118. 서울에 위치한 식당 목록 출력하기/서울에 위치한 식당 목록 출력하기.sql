WITH B AS(
    SELECT RR.REST_ID AS REST_ID, AVG(RR.REVIEW_SCORE) AS SCORE
    FROM REST_REVIEW AS RR
    JOIN REST_INFO AS RI ON RR.REST_ID=RI.REST_ID
    WHERE RI.ADDRESS LIKE '서울%'
    GROUP BY RR.REST_ID
)

SELECT A.REST_ID, A.REST_NAME, A.FOOD_TYPE, A.FAVORITES, A.ADDRESS, ROUND(B.SCORE,2)
FROM REST_INFO AS A
JOIN B ON A.REST_ID=B.REST_ID
ORDER BY B.SCORE DESC, FAVORITES DESC