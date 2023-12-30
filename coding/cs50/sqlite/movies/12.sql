SELECT title FROM movies WHERE id IN (
    SELECT movie_id FROM stars WHERE person_id IN (
        SELECT id FROM people WHERE name IN ("Helena Bonham Carter", "Johnny Depp")
    )
    GROUP BY movie_id
    HAVING COUNT(movie_id) = 2
);