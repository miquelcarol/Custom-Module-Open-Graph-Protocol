
This custom module is a fork of a simple module shared to Drupal community by Joe Mooring, on October 16, 2010 as a comment of first Open Graph Protocol module project of Drupal comunity.

http://drupal.org/node/784904#comment-3582838

This forked version adds some extra funcionalities, to show a specific image on Facebook likes and shares, and extra admin metatags on specific nodes.

Extra image metatag require:

Content Construction Kit Drupal module (CCK)
Install imagefield and filefield Drupal modules.
Make a extra field on nodes with name 'field_imagefb'.

Can see the easy implementation on the youtube video of the next link.

http://www.miquelcarol.com/drupal6/modulos/usando-el-protocolo-open-graph-de-forma-automatica/22-03-2011


CONTENTS OF THIS FILE
---------------------

* Introduction
* Installation
* Frequently Asked Questions
* Known Issues
* How Can You Contribute?

INTRODUCTION
------------

Contributer: Joe Mooring <http://drupal.org/user/408638>
Project Page: http://drupal.org/project/og_meta_tags

This module places Open Graph protocol <meta> tags on selected node
types.

The title, description and url tags are dynamically generated based on
the current node's title, teaser and url respectively. Defaults for all
other values are statically defined on the module's administrative page.
You may override some of the statically defined values per content type
by editing the content type.

If you have installed and configured the Facebook social plugins
integration module, the Facebook Application ID for this module will
default to the Facebook Application ID as defined on the Facebook social
plugins integration administrative settings page.

More information about the Open Graph protocol may be found at
http://developers.facebook.com/docs/opengraph.

INSTALLATION
------------

Add the following html tag attributes in the top of your page.tpl.php
file (and any page.tpl.php derivatives) located in your theme directory:

xmlns:og="http://opengraphprotocol.org/schema/"
xmlns:fb="http://www.facebook.com/2008/fbml"

For example:

<html xmlns:og="http://opengraphprotocol.org/schema/"
  xmlns:fb="http://www.facebook.com/2008/fbml"
  xmlns="http://www.w3.org/1999/xhtml"
  lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

If you are not planning to embed any of Facebook's social plugins in
your site, then you may exclude
xmlns:fb="http://www.facebook.com/2008/fbml" from your html tag
attributes.

See http://drupal.org/getting-started/install-contrib/modules for
instructions on how to install or update Drupal modules.

FREQUENTLY ASKED QUESTIONS
--------------------------

Q: What is the Open Graph Protocol?

A: The Open Graph protocol enables any web page to become a rich object
in a social graph. For instance, this is used on Facebook to enable any
web page to have the same functionality as a Facebook Page. While many
different technologies and schemas exist and could be combined together,
there isn't a single technology which provides enough information to
richly represent any web page within the social graph. The Open Graph
protocol builds on these existing technologies and gives developers one
thing to implement. Developer simplicity is a key goal of the Open Graph
protocol which has informed many of the technical design decisions. See
http://opengraphprotocol.org for more information.

Q: On the adminstrative page there are a couple of fields related to
Facebook (Facebook Application ID and Facebook Admins). Do I need to use
these?

A: If you are not embedding any of Facebook's social plugins
(http://developers.facebook.com/plugins) on your site then you do not
need to enter any information into these fields. While the Open Graph
protocol was developed by Facebook, it is an open standard that has
applications and merit beyond Facebook.

Q: I have embedded one or more Facebook's social plugins on my site, and
I'd like to take advantage of Open Graph protocol <meta> tags. Which of
the Facebook fields on the adminstrative page should I use?

A: You may use either one, or both. See
http://developers.facebook.com/docs/opengraph for more information.

Q: How can I be sure that the Open Graph protocol meta tags are being
properly added to my pages?

A: Use the "View Source" option in your browser.

Q: I have embedded one or more Facebook's social plugins on my site. How
can I be sure that the information is correct from Facebook's
perspective?

A: Use the Facebook "URL Linter" developer tool:
http://developers.facebook.com/tools/lint

Q: I have enabled Open Graph protocol meta tags for three content types
on my site. Instead of having all content types associated with the same
Open Graph protocol 'content type', I would each of my content types to
be associated with different Open Graph protocol 'content types'. The
administrative settings page for the Open Graph meta tags module only
allows me to select one Open Graph protocol 'content type.' What should
I do?

A: The administrative settings page for the Open Graph meta tags module
allows you to define the default Open Graph protocol 'content type' to
be associated with each of your Drupal content types. This may be
overridden per content type by editing the content type
(admin/content/types).

KNOWN ISSUES
------------

There are no known issues at this time.

To report new bug reports, feature requests, and support requests, visit
http://drupal.org/project/issues/og_meta_tags.

HOW CAN YOU CONTRIBUTE?
-----------------------

- Write a review for this module at drupalmodules.com.
http://drupalmodules.com/module/og_meta_tags

- Help translate this module on launchpad.net.
https://translations.launchpad.net/drupal-og_meta_tags

- Report any bugs, feature requests, etc. in the issue tracker.
http://drupal.org/project/issues/og_meta_tags

