<?php
// $Id$ og_meta_tags.admin.inc v0.01 2011.09.28

/**
 * @file
 * Places Open Graph protocol <meta> tags on selected node types.
 */

/**
 * Implementation of menu callback.
 */
function og_meta_tags_admin_settings() {
  $form = array();

  // fieldset: node types
  $form['node_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['node_types']['og_meta_tags_node_types'] = array(
    '#type' => 'checkboxes',
    '#description' => t('Select the content types to which Open Graph protocol meta tags should be added.'),
    '#default_value' => variable_get('og_meta_tags_node_types', array()),
    '#options' => node_get_types('names'),
  );

  // fieldset: general information
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General information'),
    '#weight' => -10,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['general']['og_meta_tags_type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('The default Open Graph protocol \'object type\' to be associated with every content type. This may be overridden per content type by editing the content type. More information on the Open Graph protocol \'object type\' may be found !url.', array('!url' => l('here', 'http://developers.facebook.com/docs/opengraph#types', array('attributes' => array('onclick' => 'window.open(this.href); return false;'))))),
    '#options' => _og_meta_tags_list_possible_types(),
    '#default_value' => variable_get('og_meta_tags_type', 'article'),
    '#required' => TRUE,
  );
  $form['general']['og_meta_tags_site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site name'),
    '#description' => t('Defaults to the site name defined at !url, but you may set a different value for the Open Graph meta data.', array('!url' => l('admin/settings/site-information', 'admin/settings/site-information', array('attributes' => array('onclick' => 'window.open(this.href); return false;'))))),
    '#default_value' => variable_get('og_meta_tags_site_name', variable_get('site_name', 'Drupal')),
    '#required' => TRUE,
  );

  // fieldset: facebook information
  $form['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook information'),
    '#description' => t('Facebook information associated with this site. Not required unless you wish to connect your pages with Facebook. You may specify either or both of the values below.'),
    '#weight' => -9,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['facebook']['og_meta_tags_fb_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Application ID'),
    '#description' => t('Defaults to the Facebook Applicaton ID specified by the Facebook social plugins integration module if this module is installed. Otherwise, !url your application on Facebook to get a Facebook Application ID.', array('!url' => l('register', 'http://developers.facebook.com/setup/', array('attributes' => array('onclick' => 'window.open(this.href); return false;'))))),
    '#default_value' => variable_get('og_meta_tags_fb_app_id', variable_get('fb_social_appid', '')),
    '#required' => FALSE,
  );
  $form['facebook']['og_meta_tags_fb_page_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook fanpage ID'),
    '#description' => t('The ID of a facebook fanpage for Insights statistics.'),
    '#default_value' => variable_get('og_meta_tags_fb_page_id', variable_get('fb_social_pageid', '')),
    '#required' => FALSE,
  );
  $form['facebook']['og_meta_tags_fb_admins'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook admins'),
    '#description' => t('A comma-separated list of Facebook user IDs that administer this page.'),
    '#default_value' => variable_get('og_meta_tags_fb_admins', ''),
    '#required' => FALSE,
  );

  // fieldset: location
  $form['location'] = array(
    '#type' => 'fieldset',
    '#title' => t('Location'),
    '#weight' => -8,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['location']['og_meta_tags_latitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude'),
    '#description' => t('The latitude associated with this site. Example: 38.890209'),
    '#default_value' => variable_get('og_meta_tags_latitude', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_longitude'] = array(
    '#type' => 'textfield',
    '#title' => t('Longitude'),
    '#description' => t('The longitude associated with this site. Example: -77.086792'),
    '#default_value' => variable_get('og_meta_tags_longitude', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_street_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Street address'),
    '#description' => t('The street address associates with this site. Example: 123 Any Street, Suite A'),
    '#default_value' => variable_get('og_meta_tags_street_address', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_locality'] = array(
    '#type' => 'textfield',
    '#title' => t('Locality'),
    '#description' => t('The city associated with this site. Example: San Francisco'),
    '#default_value' => variable_get('og_meta_tags_locality', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_region'] = array(
    '#type' => 'textfield',
    '#title' => t('Region'),
    '#description' => t('The state or province associated with this site. Example: CA'),
    '#default_value' => variable_get('og_meta_tags_region', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal code'),
    '#description' => t('The zip or postal code associated with this site. Example: 12345'),
    '#default_value' => variable_get('og_meta_tags_postal_code', ''),
    '#required' => FALSE,
  );
  $form['location']['og_meta_tags_country_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#description' => t('The country associated with this site. Example: USA'),
    '#default_value' => variable_get('og_meta_tags_country_name', ''),
    '#required' => FALSE,
  );

  // fieldset: contact
  $form['contact'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact'),
    '#weight' => -7,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['contact']['og_meta_tags_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#description' => t('The primary email address associated with this site. Example: info@example.com'),
    '#default_value' => variable_get('og_meta_tags_email', ''),
    '#required' => FALSE,
  );
  $form['contact']['og_meta_tags_phone_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#description' => t('The primary phone number associated with this site: Example: +1-800-555-1212'),
    '#default_value' => variable_get('og_meta_tags_phone_number', ''),
    '#required' => FALSE,
  );
  $form['contact']['og_meta_tags_fax_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax number'),
    '#description' => t('The primary fax number associated with this site: Example: +1-800-555-8989'),
    '#default_value' => variable_get('og_meta_tags_fax_number', ''),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
