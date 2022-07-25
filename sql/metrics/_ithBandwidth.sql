/*PGR-GNU*****************************************************************
File: _ithBandwidth.sql

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

---------------------------
-- _pgr_ithBandwidth
---------------------------


--v3.3.1
CREATE FUNCTION _pgr_ithBandwidth(
    edges_sql TEXT,

    OUT node BIGINT,
    OUT ithBandwidth BIGINT)

RETURNS SETOF RECORD AS
'MODULE_PATHNAME'
LANGUAGE C VOLATILE STRICT;


-- COMMENTS


COMMENT ON FUNCTION _pgr_ithBandwidth(TEXT)
IS 'pgRouting internal function';