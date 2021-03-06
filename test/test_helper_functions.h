/*-------------------------------------------------------------------------
 *
 * test/test_helper_functions.h
 *
 * Declarations for public functions and types related to unit testing
 * functionality.
 *
 * Copyright (c) 2014, Citus Data, Inc.
 *
 *-------------------------------------------------------------------------
 */

#ifndef PG_SHARD_TEST_HELPER_FUNCTIONS_H
#define PG_SHARD_TEST_HELPER_FUNCTIONS_H

#include "postgres.h"
#include "fmgr.h"
#include "postgres_ext.h"

#include "utils/array.h"


/* SQL statements for testing */
#define POPULATE_TEMP_TABLE "CREATE TEMPORARY TABLE numbers " \
							"AS SELECT * FROM generate_series(1, 100);"
#define COUNT_TEMP_TABLE    "SELECT COUNT(*) FROM numbers;"


/* function declarations for generic test functions */
extern ArrayType * DatumArrayToArrayType(Datum *datumArray, int datumCount,
                                         Oid datumTypeId);

/* function declarations for exercising connection functions */
extern Datum initialize_remote_temp_table(PG_FUNCTION_ARGS);
extern Datum count_remote_temp_table_rows(PG_FUNCTION_ARGS);
extern Datum get_and_purge_connection(PG_FUNCTION_ARGS);

/* function declarations for exercising metadata functions */
extern Datum load_shard_id_array(PG_FUNCTION_ARGS);
extern Datum load_shard_interval_array(PG_FUNCTION_ARGS);
extern Datum load_shard_placement_array(PG_FUNCTION_ARGS);
extern Datum partition_column_id(PG_FUNCTION_ARGS);
extern Datum insert_hash_partition_row(PG_FUNCTION_ARGS);
extern Datum insert_monolithic_shard_row(PG_FUNCTION_ARGS);
extern Datum insert_healthy_local_shard_placement_row(PG_FUNCTION_ARGS);
extern Datum delete_shard_placement_row(PG_FUNCTION_ARGS);
extern Datum next_shard_id(PG_FUNCTION_ARGS);
extern Datum acquire_shared_shard_lock(PG_FUNCTION_ARGS);

/* function declarations for exercising ddl generation functions */
extern Datum table_ddl_command_array(PG_FUNCTION_ARGS);
extern Datum alter_server_host_and_port_command(PG_FUNCTION_ARGS);

/* function declarations for exercising ddl extension functions */
extern Datum extend_ddl_command(PG_FUNCTION_ARGS);
extern Datum extend_name(PG_FUNCTION_ARGS);

/* function declarations for exercising shard creation functions */
extern Datum sort_names(PG_FUNCTION_ARGS);
extern Datum create_table_then_fail(PG_FUNCTION_ARGS);

/* function declarations for exercising shard pruning functions */
extern Datum prune_using_no_values(PG_FUNCTION_ARGS);
extern Datum prune_using_single_value(PG_FUNCTION_ARGS);
extern Datum prune_using_either_value(PG_FUNCTION_ARGS);
extern Datum prune_using_both_values(PG_FUNCTION_ARGS);
extern Datum debug_equality_expression(PG_FUNCTION_ARGS);


#endif /* PG_SHARD_TEST_HELPER_FUNCTIONS_H */
