SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS d
WHERE (select code from skillcodes where name = 'Python') & d.skill_code > 0 
or (select code from skillcodes where name = 'C#') & d.skill_code > 0 
ORDER BY ID;