/*PGR-GNU*****************************************************************
File: vertexBetweennessCentrality.sql

Generated with Template by:
Copyright (c) 2022 pgRouting developers
Mail: project@pgrouting.org

Function's developer:
Copyright (c) 2022 Sanskar Bhushan
Mail: sbdtu5498@gmail.com

------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

********************************************************************PGR-GNU*/

----------------------------------
-- pgr_vertexBetweennessCentrality
----------------------------------


--v3.3.1
CREATE FUNCTION pgr_vertexBetweennessCentrality(
    TEXT,    -- edges_sql (required)

    directed BOOLEAN DEFAULT true,

    OUT node BIGINT,
    OUT absolute_BC BIGINT,
    OUT relative_BC BIGINT)

RETURNS SETOF RECORD AS
$BODY$
BEGIN
    RETURN QUERY
    SELECT *
    FROM _pgr_vertexBetweennessCentrality(_pgr_get_statement($1), directed);
END;
$BODY$
LANGUAGE plpgsql VOLATILE STRICT;

-- COMMENTS

COMMENT ON FUNCTION pgr_vertexBetweennessCentrality(TEXT, BOOLEAN)
IS 'pgr_vertexBetweennessCentrality
- Experimental
- Parameters:
    - Edges SQL with columns: id, source, target, cost [,reverse_cost]
- Optional parameters
    - directed := true
- Documentation:
    - ${PROJECT_DOC_LINK}/pgr_vertexBetweennessCentrality.html
';