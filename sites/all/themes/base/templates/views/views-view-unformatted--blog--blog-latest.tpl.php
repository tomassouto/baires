<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * Added rich snippets tags
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?> itemscope="" itemtype="http://schema.org/BlogPosting">
        <?php print $row; ?>
    </div>
<?php endforeach; ?>