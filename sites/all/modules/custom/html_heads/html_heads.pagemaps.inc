<?php
/**
 * Find custom pagemap for the current path
 * @param $path
 */
function html_heads_pagemaps_process($path)
{

    $heads = '';

    if (preg_match('/^blog/i', $path)) {
        $heads .= html_heads_pagemaps_process_wildcard('blog/*');
    }


    return $heads;
}

function html_heads_pagemaps_process_wildcard($path)
{
    $query = db_select('{node}', 'node');
    $query->fields('node', array('created'));
    $query->fields('field_data_body', array('body_value'));
    $query->leftJoin('{field_data_field_path}', 'field_data_field_path', 'node.nid = field_data_field_path.entity_id');
    $query->leftJoin('{field_data_body}', 'field_data_body', 'node.nid = field_data_body.entity_id');
    $query->condition('field_data_field_path.field_path_value', $path);
    $query->condition('node.type', array('html_head'), 'IN');
    $query->condition('node.status', 1);
    $query->orderBy('node.created', 'ASC');
    $results = $query->execute();

    $heads = '';

    foreach ($results AS $result) {
        $heads .= html_heads_parser($result->body_value);
    }

    return $heads;
}
