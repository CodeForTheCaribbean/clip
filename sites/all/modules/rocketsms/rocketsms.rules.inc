<?php
/**
* @file
* Adds Rules integration
*/

/**
 * Implements hook_rules_action_info().
 */
function rocketsms_rules_action_info() {
  $defaults = array(
    'group' => t('RocketSMS'),
    'module' => 'rocketsms',
  );
  
  return array(
    'rocketsms_create_contact' => $defaults + array(
      'label' => t('Create contact'),
      'parameter' => array(
        'number' => array(
          'type' => 'text',
          'label' => t('Mobile number'),
          'description' => t('Contact mobile number.'),
        ),
        'name' => array(
          'type' => 'text',
          'label' => t('Name'),
          'description' => t('Contact name.'),
          'optional' => TRUE,
        ),
      ),
    ),
    'rocketsms_delete_contact' => $defaults + array(
      'label' => t('Delete contact'),
      'parameter' => array(
        'contact_id' => array(
          'type' => 'integer',
          'label' => t('Contact ID'),
          'description' => t('ID for contact to delete.'),
        ),
      ),
    ),
    'rocketsms_create_group' => $defaults + array(
      'label' => t('Create group'),
      'parameter' => array(
        'name' => array(
          'type' => 'text',
          'label' => t('Name'),
          'description' => t('Group na\me.'),
        ),
        'descripton' => array(
          'type' => 'text',
          'label' => t('Description'),
          'description' => t('Group description.'),
          'optional' => TRUE,
        ),
      ),
    ),
    'rocketsms_delete_group' => $defaults + array(
      'label' => t('Delete group'),
      'parameter' => array(
        'group_id' => array(
          'type' => 'integer',
          'label' => t('Group ID'),
          'description' => t('ID for group to delete.'),
          'options list' => 'rocketsms_group_index',
        ),
      ),
    ),
    'rocketsms_group_contact_add' => $defaults + array(
      'label' => t('Add contact to group'),
      'parameter' => array(
        'group_id' => array(
          'type' => 'integer',
          'label' => t('Group ID'),
          'options list' => 'rocketsms_group_index',
        ),
        'contact_id' => array(
          'type' => 'integer',
          'label' => t('Contact ID'),
        ),
      ),
    ),
    'rocketsms_group_contact_remove' => $defaults + array(
      'label' => t('Remove contact from group'),
      'parameter' => array(
        'group_id' => array(
          'type' => 'integer',
          'label' => t('Group ID'),
          'options list' => 'rocketsms_group_index',
        ),
        'contact_id' => array(
          'type' => 'text',
          'label' => t('Contact ID'),
        ),
      ),
    ),
    'rocketsms_create_tag' => $defaults + array(
      'label' => t('Create tag'),
      'parameter' => array(
        'name' => array(
          'type' => 'text',
          'label' => t('Name'),
        ),
        'descripton' => array(
          'type' => 'text',
          'label' => t('Description'),
          'optional' => TRUE,
        ),
      ),
    ),
    'rocketsms_delete_tag' => $defaults + array(
      'label' => t('Delete tag'),
      'parameter' => array(
        'tag_id' => array(
          'type' => 'integer',
          'label' => t('Tag ID'),
          'options list' => 'rocketsms_tag_index',
        ),
      ),
    ), 
    'rocketsms_contact_tag_add' => $defaults + array(
      'label' => t('Add tag to contact'),
      'parameter' => array(
        'contact_id' => array(
          'type' => 'integer',
          'label' => t('Contact ID'),
        ),
        'tag_id' => array(
          'type' => 'integer',
          'label' => t('Tag ID'),
          'options list' => 'rocketsms_tag_index',
        ),
      ),
    ),
    'rocketsms_contact_tag_remove' => $defaults + array(
      'label' => t('Remove tag from contact'),
      'parameter' => array(
        'contact_id' => array(
          'type' => 'integer',
          'label' => t('Contact ID'),
        ),
        'tag_id' => array(
          'type' => 'integer',
          'label' => t('Tag ID'),
          'options list' => 'rocketsms_tag_index',
        ),
      ),
    ),
    'rocketsms_users_send' => $defaults + array(
      'label' => t('Send SMS to users'),
      'parameter' => array(
        'to' => array(
          'type' => 'list',
          'label' => t('Users'),
          'description' => t('A list of users (VBO provides such a list to Rules)')
        ),
        'field' => array(
          'type' => 'text',
          'label' => t('Field'),
          'description' => t('The name of the field that stores the phone number.'),
          'options list' => 'rules_condition_entity_has_field_options',
          'restriction' => 'input',
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('Sender'),
          'description' => 'If phone number: max 18 characters. If alpah-numeric: max 11 characters.',
          'optional' => TRUE,
          'default value' => NULL,
          'allow null' => TRUE,
        ),
      ),
    ),
  );
}

/**
* Implementation of hook_rules_data_info_alter
* 
* @param mixed $data_info
*/
function rocketsms_rules_data_info_alter(&$data_info) {
  $data = array(
    'to' => array(
      'type' => 'text',
      'label' => t('The local number the message was sent to'),
    ),
    'contact_id' => array(
      'type' => 'integer',
      'label' => t('The RocketSMS contact_id for the sender of the message'),
    )
  );
  
  $data_info['sms']['property info'] += $data;
}