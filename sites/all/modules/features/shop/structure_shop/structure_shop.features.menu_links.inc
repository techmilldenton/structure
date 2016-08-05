<?php
/**
 * @file
 * structure_shop.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function structure_shop_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_404-page:node/61.
  $menu_links['main-menu_404-page:node/61'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/61',
    'router_path' => 'node/%',
    'link_title' => '404 Page',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_404-page:node/61',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_about-us-basic:node/18.
  $menu_links['main-menu_about-us-basic:node/18'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'About Us Basic',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_about-us-basic:node/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_about-us:node/13.
  $menu_links['main-menu_about-us:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_about-us:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_all-projects-layout-1---full-width:node/63.
  $menu_links['main-menu_all-projects-layout-1---full-width:node/63'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/63',
    'router_path' => 'node/%',
    'link_title' => 'All Projects Layout 1 - Full Width',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-projects-layout-1---full-width:node/63',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_all-projects-layout-2--boxed-1:node/64.
  $menu_links['main-menu_all-projects-layout-2--boxed-1:node/64'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/64',
    'router_path' => 'node/%',
    'link_title' => 'All Projects Layout 2 – Boxed 1',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-projects-layout-2--boxed-1:node/64',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_all-projects-layout-3--boxed-2:node/65.
  $menu_links['main-menu_all-projects-layout-3--boxed-2:node/65'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/65',
    'router_path' => 'node/%',
    'link_title' => 'All Projects Layout 3 – Boxed 2',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-projects-layout-3--boxed-2:node/65',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_all-services-layout-01:node/14.
  $menu_links['main-menu_all-services-layout-01:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'All Services Layout 01',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-services-layout-01:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_all-services-layout-02:node/15.
  $menu_links['main-menu_all-services-layout-02:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'All Services Layout 02',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_all-services-layout-02:node/15',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_all-services-layout-03:node/17.
  $menu_links['main-menu_all-services-layout-03:node/17'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/17',
    'router_path' => 'node/%',
    'link_title' => 'All Services Layout 03',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_all-services-layout-03:node/17',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_architecture:node/19.
  $menu_links['main-menu_architecture:node/19'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/19',
    'router_path' => 'node/%',
    'link_title' => 'Architecture',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_architecture:node/19',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_blog:node/37.
  $menu_links['main-menu_blog:node/37'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/37',
    'router_path' => 'node/%',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_blog:node/37',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_building-renovation:node/20.
  $menu_links['main-menu_building-renovation:node/20'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/20',
    'router_path' => 'node/%',
    'link_title' => 'Building Renovation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_building-renovation:node/20',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_cart:cart.
  $menu_links['main-menu_cart:cart'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'cart',
    'router_path' => 'cart',
    'link_title' => 'Cart',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_cart:cart',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_shop:node/78',
  );
  // Exported menu link: main-menu_certifications:node/21.
  $menu_links['main-menu_certifications:node/21'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/21',
    'router_path' => 'node/%',
    'link_title' => 'Certifications',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_certifications:node/21',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_checkout:checkout.
  $menu_links['main-menu_checkout:checkout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'checkout',
    'router_path' => 'checkout',
    'link_title' => 'Checkout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_checkout:checkout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_shop:node/78',
  );
  // Exported menu link: main-menu_classic-blog-layout:node/37.
  $menu_links['main-menu_classic-blog-layout:node/37'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/37',
    'router_path' => 'node/%',
    'link_title' => 'Classic Blog Layout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_classic-blog-layout:node/37',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:node/37',
  );
  // Exported menu link: main-menu_company-history:node/27.
  $menu_links['main-menu_company-history:node/27'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/27',
    'router_path' => 'node/%',
    'link_title' => 'Company History',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_company-history:node/27',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_company:node/13.
  $menu_links['main-menu_company:node/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'Company',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_company:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_concrete-transport:node/22.
  $menu_links['main-menu_concrete-transport:node/22'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/22',
    'router_path' => 'node/%',
    'link_title' => 'Concrete Transport',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_concrete-transport:node/22',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_consulting:node/23.
  $menu_links['main-menu_consulting:node/23'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/23',
    'router_path' => 'node/%',
    'link_title' => 'Consulting',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_consulting:node/23',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_contact-1:node/55.
  $menu_links['main-menu_contact-1:node/55'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/55',
    'router_path' => 'node/%',
    'link_title' => 'Contact 1',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact-1:node/55',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/55',
  );
  // Exported menu link: main-menu_contact-2:node/56.
  $menu_links['main-menu_contact-2:node/56'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/56',
    'router_path' => 'node/%',
    'link_title' => 'Contact 2',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact-2:node/56',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_contact:node/55',
  );
  // Exported menu link: main-menu_contact:node/55.
  $menu_links['main-menu_contact:node/55'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/55',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact:node/55',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_core-values:node/24.
  $menu_links['main-menu_core-values:node/24'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/24',
    'router_path' => 'node/%',
    'link_title' => 'Core Values',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_core-values:node/24',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_design--build-package:node/25.
  $menu_links['main-menu_design--build-package:node/25'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/25',
    'router_path' => 'node/%',
    'link_title' => 'Design & Build Package',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_design--build-package:node/25',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_services:node/14',
  );
  // Exported menu link: main-menu_faq:node/26.
  $menu_links['main-menu_faq:node/26'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/26',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_faq:node/26',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_grid-blog-layout-01:node/43.
  $menu_links['main-menu_grid-blog-layout-01:node/43'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/43',
    'router_path' => 'node/%',
    'link_title' => 'Grid Blog Layout 01',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_grid-blog-layout-01:node/43',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:node/37',
  );
  // Exported menu link: main-menu_grid-blog-layout-02:node/44.
  $menu_links['main-menu_grid-blog-layout-02:node/44'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/44',
    'router_path' => 'node/%',
    'link_title' => 'Grid Blog Layout 02',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_grid-blog-layout-02:node/44',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:node/37',
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_homepage---black-edition:node/10.
  $menu_links['main-menu_homepage---black-edition:node/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/10',
    'router_path' => 'node/%',
    'link_title' => 'Homepage - Black Edition',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage---black-edition:node/10',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage---default-edition:node/11.
  $menu_links['main-menu_homepage---default-edition:node/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/11',
    'router_path' => 'node/%',
    'link_title' => 'Homepage - Default Edition',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage---default-edition:node/11',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage---shop:node/81.
  $menu_links['main-menu_homepage---shop:node/81'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/81',
    'router_path' => 'node/%',
    'link_title' => 'Homepage - Shop',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage---shop:node/81',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage---white-edition:node/12.
  $menu_links['main-menu_homepage---white-edition:node/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Homepage - White Edition',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage---white-edition:node/12',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-01---header-type-1:node/1.
  $menu_links['main-menu_homepage-01---header-type-1:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 01 - Header Type 1',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage-01---header-type-1:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-02---header-type-2:node/2.
  $menu_links['main-menu_homepage-02---header-type-2:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 02 - Header Type 2',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage-02---header-type-2:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-03---header-type-3:node/3.
  $menu_links['main-menu_homepage-03---header-type-3:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 03 - Header Type 3',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage-03---header-type-3:node/3',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-04---header-transparent:node/4.
  $menu_links['main-menu_homepage-04---header-transparent:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 04 - Header Transparent',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-04---header-transparent:node/4',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-05---header-type-5:node/5.
  $menu_links['main-menu_homepage-05---header-type-5:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 05 - Header Type 5',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage-05---header-type-5:node/5',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-06---header-type-6:node/6.
  $menu_links['main-menu_homepage-06---header-type-6:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 06 - Header Type 6',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_homepage-06---header-type-6:node/6',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-07---modern-demo:node/7.
  $menu_links['main-menu_homepage-07---modern-demo:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 07 - Modern Demo',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-07---modern-demo:node/7',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-08---fullscreen-slider:node/8.
  $menu_links['main-menu_homepage-08---fullscreen-slider:node/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 08 - Fullscreen Slider',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-08---fullscreen-slider:node/8',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-09:node/9.
  $menu_links['main-menu_homepage-09:node/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 09',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-09:node/9',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -38,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-10:node/31.
  $menu_links['main-menu_homepage-10:node/31'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/31',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 10',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-10:node/31',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -37,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-11:node/32.
  $menu_links['main-menu_homepage-11:node/32'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/32',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 11',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-11:node/32',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -36,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_homepage-12:node/33.
  $menu_links['main-menu_homepage-12:node/33'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/33',
    'router_path' => 'node/%',
    'link_title' => 'Homepage 12',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_homepage-12:node/33',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -35,
    'customized' => 1,
    'parent_identifier' => 'main-menu_home:<front>',
  );
  // Exported menu link: main-menu_our-partners:node/28.
  $menu_links['main-menu_our-partners:node/28'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/28',
    'router_path' => 'node/%',
    'link_title' => 'Our Partners',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_our-partners:node/28',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_our-team:node/29.
  $menu_links['main-menu_our-team:node/29'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/29',
    'router_path' => 'node/%',
    'link_title' => 'Our Team',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_our-team:node/29',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_pricing:node/30.
  $menu_links['main-menu_pricing:node/30'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/30',
    'router_path' => 'node/%',
    'link_title' => 'Pricing',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_pricing:node/30',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_project-detail-page---layout-01:node/58.
  $menu_links['main-menu_project-detail-page---layout-01:node/58'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/58',
    'router_path' => 'node/%',
    'link_title' => 'Project Detail Page - Layout 01',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_project-detail-page---layout-01:node/58',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_project-detail-page---layout-02:node/59.
  $menu_links['main-menu_project-detail-page---layout-02:node/59'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/59',
    'router_path' => 'node/%',
    'link_title' => 'Project Detail Page - Layout 02',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_project-detail-page---layout-02:node/59',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_project-detail-page---layout-03:node/60.
  $menu_links['main-menu_project-detail-page---layout-03:node/60'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/60',
    'router_path' => 'node/%',
    'link_title' => 'Project Detail Page - Layout 03',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_project-detail-page---layout-03:node/60',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_projects:node/63',
  );
  // Exported menu link: main-menu_projects:node/63.
  $menu_links['main-menu_projects:node/63'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/63',
    'router_path' => 'node/%',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_projects:node/63',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_reviews:node/16.
  $menu_links['main-menu_reviews:node/16'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/16',
    'router_path' => 'node/%',
    'link_title' => 'Reviews',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_reviews:node/16',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: main-menu_services:node/14.
  $menu_links['main-menu_services:node/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Services',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_services:node/14',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_shop-fullwidth:node/80.
  $menu_links['main-menu_shop-fullwidth:node/80'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/80',
    'router_path' => 'node/%',
    'link_title' => 'Shop Fullwidth',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_shop-fullwidth:node/80',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_shop:node/78',
  );
  // Exported menu link: main-menu_shop:node/78.
  $menu_links['main-menu_shop:node/78'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/78',
    'router_path' => 'node/%',
    'link_title' => 'Shop',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_shop:node/78',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_single-post:node/42.
  $menu_links['main-menu_single-post:node/42'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/42',
    'router_path' => 'node/%',
    'link_title' => 'Single Post',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_single-post:node/42',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:node/37',
  );
  // Exported menu link: main-menu_under-construction:node/62.
  $menu_links['main-menu_under-construction:node/62'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/62',
    'router_path' => 'node/%',
    'link_title' => 'Under Construction',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_under-construction:node/62',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'customized' => 1,
    'parent_identifier' => 'main-menu_company:node/13',
  );
  // Exported menu link: management_account-settings:admin/config/people/accounts.
  $menu_links['management_account-settings:admin/config/people/accounts'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/accounts',
    'router_path' => 'admin/config/people/accounts',
    'link_title' => 'Account settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure default behavior of users, including registration requirements, e-mails, fields, and user pictures.',
      ),
      'identifier' => 'management_account-settings:admin/config/people/accounts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_people:admin/config/people',
  );
  // Exported menu link: management_actions:admin/config/system/actions.
  $menu_links['management_actions:admin/config/system/actions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/actions',
    'router_path' => 'admin/config/system/actions',
    'link_title' => 'Actions',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage the actions defined for your site.',
      ),
      'identifier' => 'management_actions:admin/config/system/actions',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_system:admin/config/system',
  );
  // Exported menu link: management_add-a-customer-profile:admin/commerce/customer-profiles/add.
  $menu_links['management_add-a-customer-profile:admin/commerce/customer-profiles/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/customer-profiles/add',
    'router_path' => 'admin/commerce/customer-profiles/add',
    'link_title' => 'Add a customer profile',
    'options' => array(
      'attributes' => array(
        'title' => 'Add a new customer profile.',
      ),
      'identifier' => 'management_add-a-customer-profile:admin/commerce/customer-profiles/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_customer-profiles:admin/commerce/customer-profiles',
  );
  // Exported menu link: management_add-a-payment-method-rule:admin/commerce/config/payment-methods/add.
  $menu_links['management_add-a-payment-method-rule:admin/commerce/config/payment-methods/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/payment-methods/add',
    'router_path' => 'admin/commerce/config/payment-methods/add',
    'link_title' => 'Add a payment method rule',
    'options' => array(
      'attributes' => array(
        'title' => 'Adds an additional payment method rule configuration.',
      ),
      'identifier' => 'management_add-a-payment-method-rule:admin/commerce/config/payment-methods/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_payment-methods:admin/commerce/config/payment-methods',
  );
  // Exported menu link: management_add-a-product:admin/commerce/products/add.
  $menu_links['management_add-a-product:admin/commerce/products/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/products/add',
    'router_path' => 'admin/commerce/products/add',
    'link_title' => 'Add a product',
    'options' => array(
      'attributes' => array(
        'title' => 'Add a new product for sale.',
      ),
      'identifier' => 'management_add-a-product:admin/commerce/products/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_products:admin/commerce/products',
  );
  // Exported menu link: management_administration:admin.
  $menu_links['management_administration:admin'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin',
    'router_path' => 'admin',
    'link_title' => 'Administration',
    'options' => array(
      'identifier' => 'management_administration:admin',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
  );
  // Exported menu link: management_appearance:admin/appearance.
  $menu_links['management_appearance:admin/appearance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/appearance',
    'router_path' => 'admin/appearance',
    'link_title' => 'Appearance',
    'options' => array(
      'attributes' => array(
        'title' => 'Select and configure your themes.',
      ),
      'identifier' => 'management_appearance:admin/appearance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -6,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_available-updates:admin/reports/updates.
  $menu_links['management_available-updates:admin/reports/updates'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/updates',
    'router_path' => 'admin/reports/updates',
    'link_title' => 'Available updates',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about available updates for your installed modules and themes.',
      ),
      'identifier' => 'management_available-updates:admin/reports/updates',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_awecontent:admin/awe-content.
  $menu_links['management_awecontent:admin/awe-content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/awe-content',
    'router_path' => 'admin/awe-content',
    'link_title' => 'AWEContent',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer page, templates, import... for AWEContent',
      ),
      'identifier' => 'management_awecontent:admin/awe-content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -7,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_block-types:admin/structure/block-types.
  $menu_links['management_block-types:admin/structure/block-types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block-types',
    'router_path' => 'admin/structure/block-types',
    'link_title' => 'Block types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage block types, including fields, settings, etc.',
      ),
      'identifier' => 'management_block-types:admin/structure/block-types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_blocks:admin/content/blocks.
  $menu_links['management_blocks:admin/content/blocks'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/blocks',
    'router_path' => 'admin/content/blocks',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage blocks used on your site.',
      ),
      'identifier' => 'management_blocks:admin/content/blocks',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content:admin/content',
  );
  // Exported menu link: management_blocks:admin/structure/block.
  $menu_links['management_blocks:admin/structure/block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure what block content appears in your site\'s sidebars and other regions.',
      ),
      'identifier' => 'management_blocks:admin/structure/block',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_checkout-settings:admin/commerce/config/checkout.
  $menu_links['management_checkout-settings:admin/commerce/config/checkout'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/checkout',
    'router_path' => 'admin/commerce/config/checkout',
    'link_title' => 'Checkout settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Customize the checkout form and configure checkout rules.',
      ),
      'identifier' => 'management_checkout-settings:admin/commerce/config/checkout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_clean-urls:admin/config/search/clean-urls.
  $menu_links['management_clean-urls:admin/config/search/clean-urls'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/clean-urls',
    'router_path' => 'admin/config/search/clean-urls',
    'link_title' => 'Clean URLs',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable clean URLs for your site.',
      ),
      'identifier' => 'management_clean-urls:admin/config/search/clean-urls',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_comments:admin/content/comment.
  $menu_links['management_comments:admin/content/comment'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/comment',
    'router_path' => 'admin/content/comment',
    'link_title' => 'Comments',
    'options' => array(
      'attributes' => array(
        'title' => 'List and edit site comments and the comment approval queue.',
      ),
      'identifier' => 'management_comments:admin/content/comment',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content:admin/content',
  );
  // Exported menu link: management_config:admin/awe-content/config.
  $menu_links['management_config:admin/awe-content/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/awe-content/config',
    'router_path' => 'admin/awe-content/config',
    'link_title' => 'Config',
    'options' => array(
      'attributes' => array(
        'title' => 'Contains configuration for AWEContent Builder. Ex: fonts, css ...',
      ),
      'identifier' => 'management_config:admin/awe-content/config',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 0,
    'parent_identifier' => 'management_awecontent:admin/awe-content',
  );
  // Exported menu link: management_configuration:admin/commerce/config.
  $menu_links['management_configuration:admin/commerce/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config',
    'router_path' => 'admin/commerce/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure settings and business rules for your store.',
      ),
      'identifier' => 'management_configuration:admin/commerce/config',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 50,
    'customized' => 0,
    'parent_identifier' => 'management_store:admin/commerce',
  );
  // Exported menu link: management_configuration:admin/config.
  $menu_links['management_configuration:admin/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config',
    'router_path' => 'admin/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer settings.',
      ),
      'identifier' => 'management_configuration:admin/config',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_content-authoring:admin/config/content.
  $menu_links['management_content-authoring:admin/config/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content',
    'router_path' => 'admin/config/content',
    'link_title' => 'Content authoring',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings related to formatting and authoring content.',
      ),
      'identifier' => 'management_content-authoring:admin/config/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_content-types:admin/structure/types.
  $menu_links['management_content-types:admin/structure/types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/types',
    'router_path' => 'admin/structure/types',
    'link_title' => 'Content types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage content types, including default status, front page promotion, comment settings, etc.',
      ),
      'identifier' => 'management_content-types:admin/structure/types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_content:admin/content.
  $menu_links['management_content:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer content and comments.',
      ),
      'identifier' => 'management_content:admin/content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_create-an-order:admin/commerce/orders/add.
  $menu_links['management_create-an-order:admin/commerce/orders/add'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/orders/add',
    'router_path' => 'admin/commerce/orders/add',
    'link_title' => 'Create an order',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new order.',
      ),
      'identifier' => 'management_create-an-order:admin/commerce/orders/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_orders:admin/commerce/orders',
  );
  // Exported menu link: management_create-name:admin/commerce/customer-profiles/add/billing.
  $menu_links['management_create-name:admin/commerce/customer-profiles/add/billing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/customer-profiles/add/billing',
    'router_path' => 'admin/commerce/customer-profiles/add/billing',
    'link_title' => 'Create @name',
    'options' => array(
      'attributes' => array(
        'title' => 'The profile used to collect billing information on the checkout and order forms.',
      ),
      'identifier' => 'management_create-name:admin/commerce/customer-profiles/add/billing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_add-a-customer-profile:admin/commerce/customer-profiles/add',
  );
  // Exported menu link: management_create-name:admin/commerce/products/add/product.
  $menu_links['management_create-name:admin/commerce/products/add/product'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/products/add/product',
    'router_path' => 'admin/commerce/products/add/product',
    'link_title' => 'Create !name',
    'options' => array(
      'attributes' => array(
        'title' => 'A basic product type.',
      ),
      'identifier' => 'management_create-name:admin/commerce/products/add/product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_add-a-product:admin/commerce/products/add',
  );
  // Exported menu link: management_cron:admin/config/system/cron.
  $menu_links['management_cron:admin/config/system/cron'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/cron',
    'router_path' => 'admin/config/system/cron',
    'link_title' => 'Cron',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage automatic site maintenance tasks.',
      ),
      'identifier' => 'management_cron:admin/config/system/cron',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_system:admin/config/system',
  );
  // Exported menu link: management_currency-settings:admin/commerce/config/currency.
  $menu_links['management_currency-settings:admin/commerce/config/currency'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/currency',
    'router_path' => 'admin/commerce/config/currency',
    'link_title' => 'Currency settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the default currency and display settings.',
      ),
      'identifier' => 'management_currency-settings:admin/commerce/config/currency',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_customer-profiles:admin/commerce/customer-profiles.
  $menu_links['management_customer-profiles:admin/commerce/customer-profiles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/customer-profiles',
    'router_path' => 'admin/commerce/customer-profiles',
    'link_title' => 'Customer profiles',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customer profiles and profile types in the store.',
      ),
      'identifier' => 'management_customer-profiles:admin/commerce/customer-profiles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_store:admin/commerce',
  );
  // Exported menu link: management_dashboard:admin/dashboard.
  $menu_links['management_dashboard:admin/dashboard'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'attributes' => array(
        'title' => 'View and customize your dashboard.',
      ),
      'identifier' => 'management_dashboard:admin/dashboard',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_date-and-time:admin/config/regional/date-time.
  $menu_links['management_date-and-time:admin/config/regional/date-time'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/date-time',
    'router_path' => 'admin/config/regional/date-time',
    'link_title' => 'Date and time',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure display formats for date and time.',
      ),
      'identifier' => 'management_date-and-time:admin/config/regional/date-time',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_regional-and-language:admin/config/regional',
  );
  // Exported menu link: management_development:admin/config/development.
  $menu_links['management_development:admin/config/development'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development',
    'router_path' => 'admin/config/development',
    'link_title' => 'Development',
    'options' => array(
      'attributes' => array(
        'title' => 'Development tools.',
      ),
      'identifier' => 'management_development:admin/config/development',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_email-contact-form-settings:admin/config/content/email.
  $menu_links['management_email-contact-form-settings:admin/config/content/email'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/email',
    'router_path' => 'admin/config/content/email',
    'link_title' => 'Email Contact Form Settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer flood control settings for email contact forms',
      ),
      'identifier' => 'management_email-contact-form-settings:admin/config/content/email',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );
  // Exported menu link: management_features:admin/structure/features.
  $menu_links['management_features:admin/structure/features'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage features.',
      ),
      'identifier' => 'management_features:admin/structure/features',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_field-collections:admin/structure/field-collections.
  $menu_links['management_field-collections:admin/structure/field-collections'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/field-collections',
    'router_path' => 'admin/structure/field-collections',
    'link_title' => 'Field collections',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage fields on field collections.',
      ),
      'identifier' => 'management_field-collections:admin/structure/field-collections',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_field-list:admin/reports/fields.
  $menu_links['management_field-list:admin/reports/fields'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/fields',
    'router_path' => 'admin/reports/fields',
    'link_title' => 'Field list',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of fields on all entity types.',
      ),
      'identifier' => 'management_field-list:admin/reports/fields',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_file-settings:admin/config/media/file-settings.
  $menu_links['management_file-settings:admin/config/media/file-settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-settings',
    'router_path' => 'admin/config/media/file-settings',
    'link_title' => 'File settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure allowed file extensions, default alt and title sources, and the file upload wizard.',
      ),
      'identifier' => 'management_file-settings:admin/config/media/file-settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_file-system:admin/config/media/file-system.
  $menu_links['management_file-system:admin/config/media/file-system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-system',
    'router_path' => 'admin/config/media/file-system',
    'link_title' => 'File system',
    'options' => array(
      'attributes' => array(
        'title' => 'Tell Drupal where to store uploaded files and how they are accessed.',
      ),
      'identifier' => 'management_file-system:admin/config/media/file-system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_file-types:admin/structure/file-types.
  $menu_links['management_file-types:admin/structure/file-types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/file-types',
    'router_path' => 'admin/structure/file-types',
    'link_title' => 'File types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage settings for the type of files used on your site.',
      ),
      'identifier' => 'management_file-types:admin/structure/file-types',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_files:admin/content/file.
  $menu_links['management_files:admin/content/file'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/file',
    'router_path' => 'admin/content/file',
    'link_title' => 'Files',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
      'identifier' => 'management_files:admin/content/file',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content:admin/content',
  );
  // Exported menu link: management_footer-menu:admin/structure/menu/manage/menu-footer.
  $menu_links['management_footer-menu:admin/structure/menu/manage/menu-footer'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/menu-footer',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Footer Menu',
    'options' => array(
      'identifier' => 'management_footer-menu:admin/structure/menu/manage/menu-footer',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_help:admin/help.
  $menu_links['management_help:admin/help'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/help',
    'router_path' => 'admin/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => 'Reference for usage, configuration, and modules.',
      ),
      'identifier' => 'management_help:admin/help',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_icons:admin/config/media/icon.
  $menu_links['management_icons:admin/config/media/icon'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/icon',
    'router_path' => 'admin/config/media/icon',
    'link_title' => 'Icons',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of all available icons.',
      ),
      'identifier' => 'management_icons:admin/config/media/icon',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_image-styles:admin/config/media/image-styles.
  $menu_links['management_image-styles:admin/config/media/image-styles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-styles',
    'router_path' => 'admin/config/media/image-styles',
    'link_title' => 'Image styles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure styles that can be used for resizing or adjusting images on display.',
      ),
      'identifier' => 'management_image-styles:admin/config/media/image-styles',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_image-toolkit:admin/config/media/image-toolkit.
  $menu_links['management_image-toolkit:admin/config/media/image-toolkit'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-toolkit',
    'router_path' => 'admin/config/media/image-toolkit',
    'link_title' => 'Image toolkit',
    'options' => array(
      'attributes' => array(
        'title' => 'Choose which image toolkit to use if you have installed optional toolkits.',
      ),
      'identifier' => 'management_image-toolkit:admin/config/media/image-toolkit',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_ip-address-blocking:admin/config/people/ip-blocking.
  $menu_links['management_ip-address-blocking:admin/config/people/ip-blocking'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/ip-blocking',
    'router_path' => 'admin/config/people/ip-blocking',
    'link_title' => 'IP address blocking',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage blocked IP addresses.',
      ),
      'identifier' => 'management_ip-address-blocking:admin/config/people/ip-blocking',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
    'parent_identifier' => 'management_people:admin/config/people',
  );
  // Exported menu link: management_jquery-update:admin/config/development/jquery_update.
  $menu_links['management_jquery-update:admin/config/development/jquery_update'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/jquery_update',
    'router_path' => 'admin/config/development/jquery_update',
    'link_title' => 'jQuery update',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure settings related to the jQuery upgrade, the library path and compression.',
      ),
      'identifier' => 'management_jquery-update:admin/config/development/jquery_update',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Exported menu link: management_line-item-types:admin/commerce/config/line-items.
  $menu_links['management_line-item-types:admin/commerce/config/line-items'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/line-items',
    'router_path' => 'admin/commerce/config/line-items',
    'link_title' => 'Line item types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage line item types for your store.',
      ),
      'identifier' => 'management_line-item-types:admin/commerce/config/line-items',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_logging-and-errors:admin/config/development/logging.
  $menu_links['management_logging-and-errors:admin/config/development/logging'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/logging',
    'router_path' => 'admin/config/development/logging',
    'link_title' => 'Logging and errors',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for logging and alerts modules. Various modules can route Drupal\'s system events to different destinations, such as syslog, database, email, etc.',
      ),
      'identifier' => 'management_logging-and-errors:admin/config/development/logging',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Exported menu link: management_main-menu:admin/structure/menu/manage/main-menu.
  $menu_links['management_main-menu:admin/structure/menu/manage/main-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/main-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Main menu',
    'options' => array(
      'identifier' => 'management_main-menu:admin/structure/menu/manage/main-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_maintenance-mode:admin/config/development/maintenance.
  $menu_links['management_maintenance-mode:admin/config/development/maintenance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/maintenance',
    'router_path' => 'admin/config/development/maintenance',
    'link_title' => 'Maintenance mode',
    'options' => array(
      'attributes' => array(
        'title' => 'Take the site offline for maintenance or bring it back online.',
      ),
      'identifier' => 'management_maintenance-mode:admin/config/development/maintenance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Exported menu link: management_management:admin/structure/menu/manage/management.
  $menu_links['management_management:admin/structure/menu/manage/management'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/management',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Management',
    'options' => array(
      'identifier' => 'management_management:admin/structure/menu/manage/management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_md-fullscreen-sliders:admin/structure/fullscreen-slider.
  $menu_links['management_md-fullscreen-sliders:admin/structure/fullscreen-slider'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/fullscreen-slider',
    'router_path' => 'admin/structure/fullscreen-slider',
    'link_title' => 'MD FullScreen Sliders',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage all full-screen sliders on your site.',
      ),
      'identifier' => 'management_md-fullscreen-sliders:admin/structure/fullscreen-slider',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_md-sliders:admin/structure/md-slider.
  $menu_links['management_md-sliders:admin/structure/md-slider'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/md-slider',
    'router_path' => 'admin/structure/md-slider',
    'link_title' => 'MD Sliders',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage all sliders',
      ),
      'identifier' => 'management_md-sliders:admin/structure/md-slider',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_media-browser-settings:admin/config/media/browser.
  $menu_links['management_media-browser-settings:admin/config/media/browser'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/browser',
    'router_path' => 'admin/config/media/browser',
    'link_title' => 'Media browser settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the behavior and display of the media browser.',
      ),
      'identifier' => 'management_media-browser-settings:admin/config/media/browser',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_media:admin/config/media',
  );
  // Exported menu link: management_media:admin/config/media.
  $menu_links['management_media:admin/config/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media',
    'router_path' => 'admin/config/media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Media tools.',
      ),
      'identifier' => 'management_media:admin/config/media',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_menu-block:admin/config/user-interface/menu-block.
  $menu_links['management_menu-block:admin/config/user-interface/menu-block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/menu-block',
    'router_path' => 'admin/config/user-interface/menu-block',
    'link_title' => 'Menu block',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure menu block.',
      ),
      'identifier' => 'management_menu-block:admin/config/user-interface/menu-block',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Exported menu link: management_menus:admin/structure/menu.
  $menu_links['management_menus:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
      'identifier' => 'management_menus:admin/structure/menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_modules:admin/modules.
  $menu_links['management_modules:admin/modules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/modules',
    'router_path' => 'admin/modules',
    'link_title' => 'Modules',
    'options' => array(
      'attributes' => array(
        'title' => 'Extend site functionality.',
      ),
      'identifier' => 'management_modules:admin/modules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -2,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_navigation:admin/structure/menu/manage/navigation.
  $menu_links['management_navigation:admin/structure/menu/manage/navigation'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/navigation',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'Navigation',
    'options' => array(
      'identifier' => 'management_navigation:admin/structure/menu/manage/navigation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_newsletters:admin/config/services/simplenews.
  $menu_links['management_newsletters:admin/config/services/simplenews'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/simplenews',
    'router_path' => 'admin/config/services/simplenews',
    'link_title' => 'Newsletters',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure your sites newsletters.',
      ),
      'identifier' => 'management_newsletters:admin/config/services/simplenews',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_web-services:admin/config/services',
  );
  // Exported menu link: management_order-settings:admin/commerce/config/order.
  $menu_links['management_order-settings:admin/commerce/config/order'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/order',
    'router_path' => 'admin/commerce/config/order',
    'link_title' => 'Order settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure general order settings, fields, and displays.',
      ),
      'identifier' => 'management_order-settings:admin/commerce/config/order',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_orders:admin/commerce/orders.
  $menu_links['management_orders:admin/commerce/orders'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/orders',
    'router_path' => 'admin/commerce/orders',
    'link_title' => 'Orders',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage orders in the store.',
      ),
      'identifier' => 'management_orders:admin/commerce/orders',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_store:admin/commerce',
  );
  // Exported menu link: management_payment-methods:admin/commerce/config/payment-methods.
  $menu_links['management_payment-methods:admin/commerce/config/payment-methods'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/payment-methods',
    'router_path' => 'admin/commerce/config/payment-methods',
    'link_title' => 'Payment methods',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable and configure payment method rule configurations.',
      ),
      'identifier' => 'management_payment-methods:admin/commerce/config/payment-methods',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_people:admin/config/people.
  $menu_links['management_people:admin/config/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people',
    'router_path' => 'admin/config/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure user accounts.',
      ),
      'identifier' => 'management_people:admin/config/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_people:admin/people.
  $menu_links['management_people:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage user accounts, roles, and permissions.',
      ),
      'identifier' => 'management_people:admin/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -4,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_performance:admin/config/development/performance.
  $menu_links['management_performance:admin/config/development/performance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/performance',
    'router_path' => 'admin/config/development/performance',
    'link_title' => 'Performance',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable page caching for anonymous users and set CSS and JS bandwidth optimization options.',
      ),
      'identifier' => 'management_performance:admin/config/development/performance',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_development:admin/config/development',
  );
  // Exported menu link: management_product-pricing-rules:admin/commerce/config/product-pricing.
  $menu_links['management_product-pricing-rules:admin/commerce/config/product-pricing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/product-pricing',
    'router_path' => 'admin/commerce/config/product-pricing',
    'link_title' => 'Product pricing rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable and configure product pricing rules and pre-calculation.',
      ),
      'identifier' => 'management_product-pricing-rules:admin/commerce/config/product-pricing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_product:admin/commerce/config/line-items/product.
  $menu_links['management_product:admin/commerce/config/line-items/product'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/line-items/product',
    'router_path' => 'admin/commerce/config/line-items/product',
    'link_title' => 'Product',
    'options' => array(
      'identifier' => 'management_product:admin/commerce/config/line-items/product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_line-item-types:admin/commerce/config/line-items',
  );
  // Exported menu link: management_products:admin/commerce/products.
  $menu_links['management_products:admin/commerce/products'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/products',
    'router_path' => 'admin/commerce/products',
    'link_title' => 'Products',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage products and product types in the store.',
      ),
      'identifier' => 'management_products:admin/commerce/products',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_store:admin/commerce',
  );
  // Exported menu link: management_recent-log-messages:admin/reports/dblog.
  $menu_links['management_recent-log-messages:admin/reports/dblog'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/dblog',
    'router_path' => 'admin/reports/dblog',
    'link_title' => 'Recent log messages',
    'options' => array(
      'attributes' => array(
        'title' => 'View events that have recently been logged.',
      ),
      'identifier' => 'management_recent-log-messages:admin/reports/dblog',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_regional-and-language:admin/config/regional.
  $menu_links['management_regional-and-language:admin/config/regional'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional',
    'router_path' => 'admin/config/regional',
    'link_title' => 'Regional and language',
    'options' => array(
      'attributes' => array(
        'title' => 'Regional settings, localization and translation.',
      ),
      'identifier' => 'management_regional-and-language:admin/config/regional',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_regional-settings:admin/config/regional/settings.
  $menu_links['management_regional-settings:admin/config/regional/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/settings',
    'router_path' => 'admin/config/regional/settings',
    'link_title' => 'Regional settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for the site\'s default time zone and country.',
      ),
      'identifier' => 'management_regional-settings:admin/config/regional/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_regional-and-language:admin/config/regional',
  );
  // Exported menu link: management_reports:admin/reports.
  $menu_links['management_reports:admin/reports'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'View reports, updates, and errors.',
      ),
      'identifier' => 'management_reports:admin/reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_rss-publishing:admin/config/services/rss-publishing.
  $menu_links['management_rss-publishing:admin/config/services/rss-publishing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/rss-publishing',
    'router_path' => 'admin/config/services/rss-publishing',
    'link_title' => 'RSS publishing',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the site description, the number of items per feed and whether feeds should be titles/teasers/full-text.',
      ),
      'identifier' => 'management_rss-publishing:admin/config/services/rss-publishing',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_web-services:admin/config/services',
  );
  // Exported menu link: management_rules:admin/config/workflow/rules.
  $menu_links['management_rules:admin/config/workflow/rules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/rules',
    'router_path' => 'admin/config/workflow/rules',
    'link_title' => 'Rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage reaction rules and rule components.',
      ),
      'identifier' => 'management_rules:admin/config/workflow/rules',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_workflow:admin/config/workflow',
  );
  // Exported menu link: management_search-and-metadata:admin/config/search.
  $menu_links['management_search-and-metadata:admin/config/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search',
    'router_path' => 'admin/config/search',
    'link_title' => 'Search and metadata',
    'options' => array(
      'attributes' => array(
        'title' => 'Local site search, metadata and SEO.',
      ),
      'identifier' => 'management_search-and-metadata:admin/config/search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_search-settings:admin/config/search/settings.
  $menu_links['management_search-settings:admin/config/search/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/settings',
    'router_path' => 'admin/config/search/settings',
    'link_title' => 'Search settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure relevance settings for search and other indexing options.',
      ),
      'identifier' => 'management_search-settings:admin/config/search/settings',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_shortcuts:admin/config/user-interface/shortcut.
  $menu_links['management_shortcuts:admin/config/user-interface/shortcut'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/shortcut',
    'router_path' => 'admin/config/user-interface/shortcut',
    'link_title' => 'Shortcuts',
    'options' => array(
      'attributes' => array(
        'title' => 'Add and modify shortcut sets.',
      ),
      'identifier' => 'management_shortcuts:admin/config/user-interface/shortcut',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_user-interface:admin/config/user-interface',
  );
  // Exported menu link: management_site-information:admin/config/system/site-information.
  $menu_links['management_site-information:admin/config/system/site-information'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/site-information',
    'router_path' => 'admin/config/system/site-information',
    'link_title' => 'Site information',
    'options' => array(
      'attributes' => array(
        'title' => 'Change site name, e-mail address, slogan, default front page, and number of posts per page, error pages.',
      ),
      'identifier' => 'management_site-information:admin/config/system/site-information',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_system:admin/config/system',
  );
  // Exported menu link: management_status-report:admin/reports/status.
  $menu_links['management_status-report:admin/reports/status'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/status',
    'router_path' => 'admin/reports/status',
    'link_title' => 'Status report',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about your site\'s operation and any detected problems.',
      ),
      'identifier' => 'management_status-report:admin/reports/status',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -60,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_store:admin/commerce.
  $menu_links['management_store:admin/commerce'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce',
    'router_path' => 'admin/commerce',
    'link_title' => 'Store',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer your store.',
      ),
      'identifier' => 'management_store:admin/commerce',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -7,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_structure:admin/structure.
  $menu_links['management_structure:admin/structure'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer blocks, content types, menus, etc.',
      ),
      'identifier' => 'management_structure:admin/structure',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -8,
    'customized' => 0,
    'parent_identifier' => 'management_administration:admin',
  );
  // Exported menu link: management_system:admin/config/system.
  $menu_links['management_system:admin/config/system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system',
    'router_path' => 'admin/config/system',
    'link_title' => 'System',
    'options' => array(
      'attributes' => array(
        'title' => 'General system related configuration.',
      ),
      'identifier' => 'management_system:admin/config/system',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_taxes:admin/commerce/config/taxes.
  $menu_links['management_taxes:admin/commerce/config/taxes'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/commerce/config/taxes',
    'router_path' => 'admin/commerce/config/taxes',
    'link_title' => 'Taxes',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage tax rates and types.',
      ),
      'identifier' => 'management_taxes:admin/commerce/config/taxes',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/commerce/config',
  );
  // Exported menu link: management_taxonomy:admin/structure/taxonomy.
  $menu_links['management_taxonomy:admin/structure/taxonomy'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'Taxonomy',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage tagging, categorization, and classification of your content.',
      ),
      'identifier' => 'management_taxonomy:admin/structure/taxonomy',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_templates:admin/awe-content/templates.
  $menu_links['management_templates:admin/awe-content/templates'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/awe-content/templates',
    'router_path' => 'admin/awe-content/templates',
    'link_title' => 'Templates',
    'options' => array(
      'attributes' => array(
        'title' => 'Contains all templates for AWEContent Builder',
      ),
      'identifier' => 'management_templates:admin/awe-content/templates',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_awecontent:admin/awe-content',
  );
  // Exported menu link: management_text-formats:admin/config/content/formats.
  $menu_links['management_text-formats:admin/config/content/formats'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/formats',
    'router_path' => 'admin/config/content/formats',
    'link_title' => 'Text formats',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how content input by users is filtered, including allowed HTML tags. Also allows enabling of module-provided filters.',
      ),
      'identifier' => 'management_text-formats:admin/config/content/formats',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );
  // Exported menu link: management_top-access-denied-errors:admin/reports/access-denied.
  $menu_links['management_top-access-denied-errors:admin/reports/access-denied'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/access-denied',
    'router_path' => 'admin/reports/access-denied',
    'link_title' => 'Top \'access denied\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'access denied\' errors (403s).',
      ),
      'identifier' => 'management_top-access-denied-errors:admin/reports/access-denied',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_top-page-not-found-errors:admin/reports/page-not-found.
  $menu_links['management_top-page-not-found-errors:admin/reports/page-not-found'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/page-not-found',
    'router_path' => 'admin/reports/page-not-found',
    'link_title' => 'Top \'page not found\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'page not found\' errors (404s).',
      ),
      'identifier' => 'management_top-page-not-found-errors:admin/reports/page-not-found',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_top-search-phrases:admin/reports/search.
  $menu_links['management_top-search-phrases:admin/reports/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/search',
    'router_path' => 'admin/reports/search',
    'link_title' => 'Top search phrases',
    'options' => array(
      'attributes' => array(
        'title' => 'View most popular search phrases.',
      ),
      'identifier' => 'management_top-search-phrases:admin/reports/search',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_url-aliases:admin/config/search/path.
  $menu_links['management_url-aliases:admin/config/search/path'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/path',
    'router_path' => 'admin/config/search/path',
    'link_title' => 'URL aliases',
    'options' => array(
      'attributes' => array(
        'title' => 'Change your site\'s URL paths by aliasing them.',
      ),
      'identifier' => 'management_url-aliases:admin/config/search/path',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'customized' => 0,
    'parent_identifier' => 'management_search-and-metadata:admin/config/search',
  );
  // Exported menu link: management_user-interface:admin/config/user-interface.
  $menu_links['management_user-interface:admin/config/user-interface'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface',
    'router_path' => 'admin/config/user-interface',
    'link_title' => 'User interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools that enhance the user interface.',
      ),
      'identifier' => 'management_user-interface:admin/config/user-interface',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_user-menu:admin/structure/menu/manage/user-menu.
  $menu_links['management_user-menu:admin/structure/menu/manage/user-menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu/manage/user-menu',
    'router_path' => 'admin/structure/menu/manage/%',
    'link_title' => 'User menu',
    'options' => array(
      'identifier' => 'management_user-menu:admin/structure/menu/manage/user-menu',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_menus:admin/structure/menu',
  );
  // Exported menu link: management_views-plugins:admin/reports/views-plugins.
  $menu_links['management_views-plugins:admin/reports/views-plugins'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/views-plugins',
    'router_path' => 'admin/reports/views-plugins',
    'link_title' => 'Views plugins',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of plugins used in all views.',
      ),
      'identifier' => 'management_views-plugins:admin/reports/views-plugins',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_reports:admin/reports',
  );
  // Exported menu link: management_views:admin/structure/views.
  $menu_links['management_views:admin/structure/views'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customized lists of content.',
      ),
      'identifier' => 'management_views:admin/structure/views',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );
  // Exported menu link: management_web-services:admin/config/services.
  $menu_links['management_web-services:admin/config/services'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services',
    'router_path' => 'admin/config/services',
    'link_title' => 'Web services',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools related to web services.',
      ),
      'identifier' => 'management_web-services:admin/config/services',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: management_webform-settings:admin/config/content/webform.
  $menu_links['management_webform-settings:admin/config/content/webform'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/webform',
    'router_path' => 'admin/config/content/webform',
    'link_title' => 'Webform settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Global configuration of webform functionality.',
      ),
      'identifier' => 'management_webform-settings:admin/config/content/webform',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );
  // Exported menu link: management_workflow:admin/config/workflow.
  $menu_links['management_workflow:admin/config/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow',
    'router_path' => 'admin/config/workflow',
    'link_title' => 'Workflow',
    'options' => array(
      'attributes' => array(
        'title' => 'Content workflow, editorial workflow tools.',
      ),
      'identifier' => 'management_workflow:admin/config/workflow',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'customized' => 0,
    'parent_identifier' => 'management_configuration:admin/config',
  );
  // Exported menu link: menu-footer_about-us:node/13.
  $menu_links['menu-footer_about-us:node/13'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_about-us:node/13',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_certifications:node/21.
  $menu_links['menu-footer_certifications:node/21'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/21',
    'router_path' => 'node/%',
    'link_title' => 'Certifications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_certifications:node/21',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_company-history:node/27.
  $menu_links['menu-footer_company-history:node/27'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/27',
    'router_path' => 'node/%',
    'link_title' => 'Company History',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_company-history:node/27',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_company:node/18.
  $menu_links['menu-footer_company:node/18'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/18',
    'router_path' => 'node/%',
    'link_title' => 'Company',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_company:node/18',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_contact:node/55.
  $menu_links['menu-footer_contact:node/55'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/55',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_contact:node/55',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_core-values:node/24.
  $menu_links['menu-footer_core-values:node/24'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/24',
    'router_path' => 'node/%',
    'link_title' => 'Core Values',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_core-values:node/24',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_faq:node/26.
  $menu_links['menu-footer_faq:node/26'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/26',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_faq:node/26',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_our-partners:node/28.
  $menu_links['menu-footer_our-partners:node/28'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/28',
    'router_path' => 'node/%',
    'link_title' => 'Our Partners',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_our-partners:node/28',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_our-team:node/29.
  $menu_links['menu-footer_our-team:node/29'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/29',
    'router_path' => 'node/%',
    'link_title' => 'Our Team',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_our-team:node/29',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_projects:node/63.
  $menu_links['menu-footer_projects:node/63'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/63',
    'router_path' => 'node/%',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-footer_projects:node/63',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: navigation_add-block:block/add.
  $menu_links['navigation_add-block:block/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'block/add',
    'router_path' => 'block/add',
    'link_title' => 'Add Block',
    'options' => array(
      'identifier' => 'navigation_add-block:block/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_add-content:node/add.
  $menu_links['navigation_add-content:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(
      'identifier' => 'navigation_add-content:node/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_add-file:file/add.
  $menu_links['navigation_add-file:file/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'file/add',
    'router_path' => 'file/add',
    'link_title' => 'Add file',
    'options' => array(
      'identifier' => 'navigation_add-file:file/add',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_article:node/add/article.
  $menu_links['navigation_article:node/add/article'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/article',
    'router_path' => 'node/add/article',
    'link_title' => 'Article',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
      ),
      'identifier' => 'navigation_article:node/add/article',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_banner:block/add/banner.
  $menu_links['navigation_banner:block/add/banner'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'block/add/banner',
    'router_path' => 'block/add/banner',
    'link_title' => 'Banner',
    'options' => array(
      'identifier' => 'navigation_banner:block/add/banner',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-block:block/add',
  );
  // Exported menu link: navigation_basic-page:node/add/page.
  $menu_links['navigation_basic-page:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Basic page',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
      ),
      'identifier' => 'navigation_basic-page:node/add/page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_compose-tips:filter/tips.
  $menu_links['navigation_compose-tips:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'identifier' => 'navigation_compose-tips:filter/tips',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_contact-header:block/add/contact-header.
  $menu_links['navigation_contact-header:block/add/contact-header'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'block/add/contact-header',
    'router_path' => 'block/add/contact-header',
    'link_title' => 'Contact Header',
    'options' => array(
      'identifier' => 'navigation_contact-header:block/add/contact-header',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-block:block/add',
  );
  // Exported menu link: navigation_icons:icons.
  $menu_links['navigation_icons:icons'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'icons',
    'router_path' => 'icons',
    'link_title' => 'Icons',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of all available icons.',
      ),
      'identifier' => 'navigation_icons:icons',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_news:node/add/news.
  $menu_links['navigation_news:node/add/news'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/news',
    'router_path' => 'node/add/news',
    'link_title' => 'News',
    'options' => array(
      'identifier' => 'navigation_news:node/add/news',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_portfolio:node/add/portfolio.
  $menu_links['navigation_portfolio:node/add/portfolio'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/portfolio',
    'router_path' => 'node/add/portfolio',
    'link_title' => 'Portfolio',
    'options' => array(
      'identifier' => 'navigation_portfolio:node/add/portfolio',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_product:node/add/product.
  $menu_links['navigation_product:node/add/product'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/product',
    'router_path' => 'node/add/product',
    'link_title' => 'Product',
    'options' => array(
      'identifier' => 'navigation_product:node/add/product',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_search:search.
  $menu_links['navigation_search:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'identifier' => 'navigation_search:search',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_shopping-cart--items:cart/my.
  $menu_links['navigation_shopping-cart--items:cart/my'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'cart/my',
    'router_path' => 'cart/my',
    'link_title' => 'Shopping cart (# items)',
    'options' => array(
      'identifier' => 'navigation_shopping-cart--items:cart/my',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_shopping-cart:cart',
  );
  // Exported menu link: navigation_shopping-cart:cart.
  $menu_links['navigation_shopping-cart:cart'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'cart',
    'router_path' => 'cart',
    'link_title' => 'Shopping cart',
    'options' => array(
      'identifier' => 'navigation_shopping-cart:cart',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: navigation_simplenews-newsletter:node/add/simplenews.
  $menu_links['navigation_simplenews-newsletter:node/add/simplenews'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/simplenews',
    'router_path' => 'node/add/simplenews',
    'link_title' => 'Simplenews newsletter',
    'options' => array(
      'attributes' => array(
        'title' => 'A newsletter issue to be sent to subscribed email addresses.',
      ),
      'identifier' => 'navigation_simplenews-newsletter:node/add/simplenews',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: navigation_webform:node/add/webform.
  $menu_links['navigation_webform:node/add/webform'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Webform',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      ),
      'identifier' => 'navigation_webform:node/add/webform',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('404 Page');
  t('AWEContent');
  t('About Us');
  t('About Us Basic');
  t('Account settings');
  t('Actions');
  t('Add Block');
  t('Add a customer profile');
  t('Add a payment method rule');
  t('Add a product');
  t('Add content');
  t('Add file');
  t('Administration');
  t('All Projects Layout 1 - Full Width');
  t('All Projects Layout 2 – Boxed 1');
  t('All Projects Layout 3 – Boxed 2');
  t('All Services Layout 01');
  t('All Services Layout 02');
  t('All Services Layout 03');
  t('Appearance');
  t('Architecture');
  t('Article');
  t('Available updates');
  t('Banner');
  t('Basic page');
  t('Block types');
  t('Blocks');
  t('Blog');
  t('Building Renovation');
  t('Cart');
  t('Certifications');
  t('Checkout');
  t('Checkout settings');
  t('Classic Blog Layout');
  t('Clean URLs');
  t('Comments');
  t('Company');
  t('Company History');
  t('Compose tips');
  t('Concrete Transport');
  t('Config');
  t('Configuration');
  t('Consulting');
  t('Contact');
  t('Contact 1');
  t('Contact 2');
  t('Contact Header');
  t('Content');
  t('Content authoring');
  t('Content types');
  t('Core Values');
  t('Create !name');
  t('Create @name');
  t('Create an order');
  t('Cron');
  t('Currency settings');
  t('Customer profiles');
  t('Dashboard');
  t('Date and time');
  t('Design & Build Package');
  t('Development');
  t('Email Contact Form Settings');
  t('FAQ');
  t('Features');
  t('Field collections');
  t('Field list');
  t('File settings');
  t('File system');
  t('File types');
  t('Files');
  t('Footer Menu');
  t('Grid Blog Layout 01');
  t('Grid Blog Layout 02');
  t('Help');
  t('Home');
  t('Homepage - Black Edition');
  t('Homepage - Default Edition');
  t('Homepage - Shop');
  t('Homepage - White Edition');
  t('Homepage 01 - Header Type 1');
  t('Homepage 02 - Header Type 2');
  t('Homepage 03 - Header Type 3');
  t('Homepage 04 - Header Transparent');
  t('Homepage 05 - Header Type 5');
  t('Homepage 06 - Header Type 6');
  t('Homepage 07 - Modern Demo');
  t('Homepage 08 - Fullscreen Slider');
  t('Homepage 09');
  t('Homepage 10');
  t('Homepage 11');
  t('Homepage 12');
  t('IP address blocking');
  t('Icons');
  t('Image styles');
  t('Image toolkit');
  t('Line item types');
  t('Log out');
  t('Logging and errors');
  t('MD FullScreen Sliders');
  t('MD Sliders');
  t('Main menu');
  t('Maintenance mode');
  t('Management');
  t('Media');
  t('Media browser settings');
  t('Menu block');
  t('Menus');
  t('Modules');
  t('Navigation');
  t('News');
  t('Newsletters');
  t('Order settings');
  t('Orders');
  t('Our Partners');
  t('Our Team');
  t('Payment methods');
  t('People');
  t('Performance');
  t('Portfolio');
  t('Pricing');
  t('Product');
  t('Product pricing rules');
  t('Products');
  t('Project Detail Page - Layout 01');
  t('Project Detail Page - Layout 02');
  t('Project Detail Page - Layout 03');
  t('Projects');
  t('RSS publishing');
  t('Recent log messages');
  t('Regional and language');
  t('Regional settings');
  t('Reports');
  t('Reviews');
  t('Rules');
  t('Search');
  t('Search and metadata');
  t('Search settings');
  t('Services');
  t('Shop');
  t('Shop Fullwidth');
  t('Shopping cart');
  t('Shopping cart (# items)');
  t('Shortcuts');
  t('Simplenews newsletter');
  t('Single Post');
  t('Site information');
  t('Status report');
  t('Store');
  t('Structure');
  t('System');
  t('Taxes');
  t('Taxonomy');
  t('Templates');
  t('Text formats');
  t('Top \'access denied\' errors');
  t('Top \'page not found\' errors');
  t('Top search phrases');
  t('URL aliases');
  t('Under Construction');
  t('User account');
  t('User interface');
  t('User menu');
  t('Views');
  t('Views plugins');
  t('Web services');
  t('Webform');
  t('Webform settings');
  t('Workflow');
  t('jQuery update');

  return $menu_links;
}
