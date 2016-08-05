<?php
/**
 * @file
 * techmill_partners.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function techmill_partners_taxonomy_default_vocabularies() {
  return array(
    'partner_level' => array(
      'name' => 'Partner Level',
      'machine_name' => 'partner_level',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'entity_type' => 'taxonomy_vocabulary',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
