<?php
/**
 * @file
 * Token callbacks for the rocketsms module.
 */
 
function rocketsms_token_info_alter(&$data) {
  $tokens = array(
    'contact-id' => array(
      'name' => t("Contact ID"), 
      'description' => t("The contact ID of the sender of this message."),
    ),
    'to' => array(
      'name' => t("Local number"), 
      'description' => t("The local number the message was sent to."),
    )
  );
  
  $data['tokens']['sms'] += $tokens;
}

/**
* Implementation of hook_tokens
* 
*/
function rocketsms_tokens($type, $tokens, array $data = array(), array $options = array()) { 
  $replacements = array();

  if ($type == 'sms' && !empty($data['sms'])) {  
    $sms = $data['sms']; 
    
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'contact-id':
          $replacements[$original] = $sms['contact_id'];
          break;
          
        case 'to':
          $replacements[$original] = $sms['to'];
          break;
      }
    }
  }

  return $replacements;
}
