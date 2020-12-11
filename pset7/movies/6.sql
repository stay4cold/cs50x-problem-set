-- SELECT avg(rating) FROM ratings WHERE movie_id IN (SELECT id FROM movies WHERE year=2012);
SELECT avg(rating) FROM ratings join movies on id==movie_id WHERE year=2012