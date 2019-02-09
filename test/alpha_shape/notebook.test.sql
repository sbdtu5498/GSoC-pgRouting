-- Data from
-- https://github.com/plotly/documentation/blob/source-design-merge/_posts/python/scientific/alpha-shapes/data-ex-2d.txt

CREATE TABLE e_test(geom geometry);
INSERT INTO e_test(geom) VALUES (ST_GeomFromText('MULTIPOINT(
(0.072213 0.616682),
(0.115641 0.256523),
(0.709330 0.077903),
(0.887964 0.372909),
(0.796091 0.624687),
(0.780431 0.069521),
(0.222984 0.266937),
(0.773456 0.151515),
(0.681843 0.500971),
(0.238492 0.623246),
(0.465003 0.922338),
(0.162313 0.481267),
(0.950678 0.447069),
(0.649028 0.803023),
(0.128857 0.013585),
(0.594825 0.671393),
(0.465626 0.745341),
(0.431693 0.989688),
(0.045125 0.219672),
(0.540694 0.005390),
(0.691728 0.573342),
(0.717810 0.898306),
(0.174244 0.180820),
(0.270756 0.310889),
(0.410399 0.182079),
(0.139572 0.704512),
(0.838489 0.642405),
(0.348582 0.240018),
(0.305693 0.803172),
(0.397964 0.863419))
') ) ;
SELECT seq, ST_Area(geom), ST_isValid(geom), ST_NPoints(geom)
FROM pgr_alphaShape1((SELECT array_agg(geom) FROM e_test), 0.15);
