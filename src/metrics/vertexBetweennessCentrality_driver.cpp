/*PGR-GNU*****************************************************************
File: vertexBetweennessCentrality_driver.cpp

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

#include "drivers/metrics/vertexBetweennessCentrality_driver.h"

#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

#include "cpp_common/pgr_alloc.hpp"
#include "cpp_common/pgr_assert.h"

#include "metrics/pgr_vertexBetweennessCentrality.hpp"

/** @file vertexBetweennessCentrality_driver.cpp
 * @brief Handles actual calling of function in the `pgr_vertexBetweennessCentrality.hpp` file.
 *
 */

/***********************************************************************
 *
 *   pgr_vertexBetweennessCentrality(
 *       edges_sql TEXT,
 *       directed BOOLEAN DEFAULT true
 *   );
 *
 ***********************************************************************/

/** @brief Calls the main function defined in the C++ Header file.
 *
 * Also sorts the root vertices in an increasing order,
 * and removes the duplicated vertices. Then calls the function
 * defined in the C++ Header file - `pgr_vertexBetweennessCentrality.hpp`
 *
 * @param graph      the graph containing the edges
 * @param directed   whether the graph is directed or undirected
 * @param log        stores the log message
 *
 * @returns results, when results are found
 */

template < class G >
std::vector < To_be_created >
pgr_vertexBetweennessCentrality(
        G &graph,
        bool directed) {
    pgrouting::functions::Pgr_vertexBetweennessCentrality < G > fn_vertexBetweennessCentrality;
    auto results = fn_vertexBetweennessCentrality.vertexBetweennessCentrality(graph, directed);
    return results;
}

/** @brief Performs exception handling and converts the results to postgres.
 *
 * @pre log_msg is empty
 * @pre notice_msg is empty
 * @pre err_msg is empty
 * @pre return_tuples is empty
 * @pre return_count is 0
 *
 * It builds the graph using the `data_edges`, depending on whether
 * the graph is directed or undirected. It also converts the C types
 * to the C++ types, such as the `rootsArr` to `roots` vector and
 * passes these variables to the template function `pgr_vertexBetweennessCentrality`
 * which calls the main function defined in the C++ Header file. It also does
 * exception handling.
 *
 * @param data_edges     the set of edges from the SQL query
 * @param total_edges    the total number of edges in the SQL query
 * @param directed       whether the graph is directed or undirected
 * @param return_tuples  the rows in the result
 * @param return_count   the count of rows in the result
 * @param log_msg        stores the log message
 * @param notice_msg     stores the notice message
 * @param err_msg        stores the error message
 *
 * @returns void
 */
void
do_pgr_vertexBetweennessCentrality(
        Edge_t  *data_edges,
        size_t total_edges,

        bool directed,

        To_be_included **return_tuples,
        size_t *return_count,

        char ** log_msg,
        char ** notice_msg,
        char ** err_msg) {
    std::ostringstream log;
    std::ostringstream err;
    std::ostringstream notice;
    try {
        pgassert(!(*log_msg));
        pgassert(!(*notice_msg));
        pgassert(!(*err_msg));
        pgassert(!(*return_tuples));
        pgassert(*return_count == 0);

        std::vector < To_be_included > results;

        graphType gType = directed ? DIRECTED : UNDIRECTED;

        if (directed) {
            pgrouting::DirectedGraph digraph(gType);
            digraph.insert_edges(data_edges, total_edges);

            results = pgr_vertexBetweennessCentrality(
                    digraph,
                    directed);
        } else {
            pgrouting::UndirectedGraph undigraph(gType);
            undigraph.insert_edges(data_edges, total_edges);

            results = pgr_vertexBetweennessCentrality(
                    undigraph,
                    directed);
        }

        auto count = results.size();

        if (count == 0) {
            (*return_tuples) = NULL;
            (*return_count) = 0;
            notice << "No metrics found";
            *log_msg = pgr_msg(notice.str().c_str());
            return;
        }

        (*return_tuples) = pgr_alloc(count, (*return_tuples));
        for (size_t i = 0; i < count; i++) {
            *((*return_tuples) + i) = results[i];
        }
        (*return_count) = count;

        pgassert(*err_msg == NULL);
        *log_msg = log.str().empty()?
            *log_msg :
            pgr_msg(log.str().c_str());
        *notice_msg = notice.str().empty()?
            *notice_msg :
            pgr_msg(notice.str().c_str());
    } catch (AssertFailedException &except) {
        (*return_tuples) = pgr_free(*return_tuples);
        (*return_count) = 0;
        err << except.what();
        *err_msg = pgr_msg(err.str().c_str());
        *log_msg = pgr_msg(log.str().c_str());
    } catch (std::exception &except) {
        (*return_tuples) = pgr_free(*return_tuples);
        (*return_count) = 0;
        err << except.what();
        *err_msg = pgr_msg(err.str().c_str());
        *log_msg = pgr_msg(log.str().c_str());
    } catch(...) {
        (*return_tuples) = pgr_free(*return_tuples);
        (*return_count) = 0;
        err << "Caught unknown exception!";
        *err_msg = pgr_msg(err.str().c_str());
        *log_msg = pgr_msg(log.str().c_str());
    }
}