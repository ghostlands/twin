
/* This file was automatically generated from m4/tree.m4, do not edit! */


/*
 *  tree_m4.h  --  internal header for libTT objects hierarchy tree
 */

#ifndef _TT_TREEM4_H
#define _TT_TREEM4_H












                                      












#define TT_TYPELIST(el) \
el(ttbyte) el(ttshort) el(ttint) el(ttcol) el(ttfont) el(ttattr) el(ttopaque) el(ttany) el(ttpointer) el(ttstring) el(ttfunction)

#define TT_LIST(el) \
el(ttobj)  el(ttevent) el(tteventbig) el(ttbitmask) el(tteventmask) el(ttcallback) el(ttlistener) el(tttimer) el(ttcomponent) el(ttdata) el(ttvisible) el(ttnative) el(ttwidget) el(ttlabel) el(tttooltip) el(ttbuttongroup) el(ttanybutton) el(ttbutton) el(ttcheckbutton) el(ttradiobutton) el(ttanyscroll) el(ttscrollbar) el(ttslider) el(ttprogressbar) el(ttscrollpane) el(ttwindow) el(ttframe) el(ttscroller) el(ttmenuitem) el(ttcheckmenuitem) el(ttradiomenuitem) el(ttmenu) el(ttmenubar) el(ttanytext) el(tttextfield) el(tttextarea) el(tttheme) el(ttapplication)

#define TT_NLIST(el) \
 el(ttevent) el(tteventbig) el(ttbitmask) el(tteventmask) el(ttcallback) el(ttlistener) el(tttimer) el(ttcomponent) el(ttdata) el(ttvisible) el(ttnative) el(ttwidget) el(ttlabel) el(tttooltip) el(ttbuttongroup) el(ttanybutton) el(ttbutton) el(ttcheckbutton) el(ttradiobutton) el(ttanyscroll) el(ttscrollbar) el(ttslider) el(ttprogressbar) el(ttscrollpane) el(ttwindow) el(ttframe) el(ttscroller) el(ttmenuitem) el(ttcheckmenuitem) el(ttradiomenuitem) el(ttmenu) el(ttmenubar) el(ttanytext) el(tttextfield) el(tttextarea) el(tttheme) el(ttapplication)

#define type_(t)	TT_CAT(type_,t)

#define super_(obj)	TT_CAT(super_,obj)
#define order_(obj)	TT_CAT(order_,obj)
#define magicmask_(obj)	TT_CAT(magicmask_,obj)
#define magic_(obj)	TT_CAT(magic_,obj)



/*
 * NOTE:
 *
 * magicmask_* and magic_* are autogenerated using a quite intricated m4 algorythm.
 *
 * the final effect is shown below, on a cutdown hierarchy tree.
 * in the picture, first number is magic_*, second is magicmask_*
 *
 *                         ________ttobj
 *                ________/   ____/(0,0)
 *       ________/       ____/       |
 *      /               /            |
 *ttcallback     ttevent        ttcomponent
 *(0x1,0x3)     (0x2,0x3)     ___(0x3,0x3)___
 *                      _____/    /     \    \_____
 *                _____/         /       \         \_____
 *               /              /         \              \
 *           _ttvisible_   ttbuttongroup   tttheme   ttapplication
 *          /(0x7,0x1F)\\__  (0xB,0x1F)   (0xF,0x1F)  (0x13,0x1F)
 *         /    |       \  \_________
 *        /     |        \           \
 * ttnative   ttwidget   ttmenuitem   ttmenubar
 *(0x27,0xFF)(0x47,0xFF) (0x67,0xFF) (0x87,0xFF)
 *
 * magic_* of a children is the parent's one, plus the progressive number
 * (conveniently shifted) of the children in the parent's children list.
 *
 * as you can see, all children of the same parent share the same magicmask;
 * this magicmask is the smallest bit mask that can hold all children magic_* numbers.
 * in other words, the tree is Huffman coded (node frequencies do not apply in this case)
 *
 * with this setup, runtime type checking and casting is extremely simple:
 * to check if an object of type A can be cast to type B, just do:
 *
 *  if ((magic_A & magicmask_B) == magic_B) {
 *      success;
 *  } else {
 *      fail;
 *  }
 * 
 */

/* set order_xxx enums */
typedef enum e_order_ttobj {
    order_ttobj = 1,
#define el(o) order_(o),
TT_NLIST(el)
#undef el
    order_n
} e_order_ttobj;


/* set type_xxx enums */
typedef enum e_type {
    type_first = order_n,
#define el(t) type_(t),
TT_TYPELIST(el)
#undef el
    type_last
} e_type;


/* set magicmask_xxx enums */
typedef enum e_magicmask_ttobj {
    magicmask_ttobj = 0, 
    magicmask_ttevent = 0x7, 
    magicmask_tteventbig = 0xf, 
    magicmask_ttbitmask = 0x7, 
    magicmask_tteventmask = 0x7, 
    magicmask_ttcallback = 0x7, 
    magicmask_ttlistener = 0xf, 
    magicmask_tttimer = 0x1f, 
    magicmask_ttcomponent = 0x7, 
    magicmask_ttdata = 0x3f, 
    magicmask_ttvisible = 0x3f, 
    magicmask_ttnative = 0x1ff, 
    magicmask_ttwidget = 0x1ff, 
    magicmask_ttlabel = 0xfff, 
    magicmask_tttooltip = 0x1fff, 
    magicmask_ttbuttongroup = 0x3f, 
    magicmask_ttanybutton = 0xfff, 
    magicmask_ttbutton = 0x3fff, 
    magicmask_ttcheckbutton = 0x7fff, 
    magicmask_ttradiobutton = 0xffff, 
    magicmask_ttanyscroll = 0x3fff, 
    magicmask_ttscrollbar = 0xffff, 
    magicmask_ttslider = 0xffff, 
    magicmask_ttprogressbar = 0xffff, 
    magicmask_ttscrollpane = 0xfff, 
    magicmask_ttwindow = 0xfff, 
    magicmask_ttframe = 0x3fff, 
    magicmask_ttscroller = 0x3fff, 
    magicmask_ttmenuitem = 0x1ff, 
    magicmask_ttcheckmenuitem = 0x7ff, 
    magicmask_ttradiomenuitem = 0xfff, 
    magicmask_ttmenu = 0x7ff, 
    magicmask_ttmenubar = 0x1ff, 
    magicmask_ttanytext = 0x3fff, 
    magicmask_tttextfield = 0x7fff, 
    magicmask_tttextarea = 0xffff, 
    magicmask_tttheme = 0x3f, 
    magicmask_ttapplication = 0x3f,
    magicmask_last
} e_magicmask_ttobj;


typedef enum e_magic_ttobj {
    magic_ttobj = 0,

 
    magic_ttevent = 0x1, 
    magic_tteventbig = 0x9, 
    magic_ttbitmask = 0x2, 
    magic_tteventmask = 0x3, 
    magic_ttcallback = 0x4, 
    magic_ttlistener = 0xc, 
    magic_tttimer = 0x1c, 
    magic_ttcomponent = 0x5, 
    magic_ttdata = 0xd, 
    magic_ttvisible = 0x15, 
    magic_ttnative = 0x55, 
    magic_ttwidget = 0x95, 
    magic_ttlabel = 0x295, 
    magic_tttooltip = 0x1295, 
    magic_ttbuttongroup = 0x1d, 
    magic_ttanybutton = 0x495, 
    magic_ttbutton = 0x1495, 
    magic_ttcheckbutton = 0x5495, 
    magic_ttradiobutton = 0xd495, 
    magic_ttanyscroll = 0x2495, 
    magic_ttscrollbar = 0x6495, 
    magic_ttslider = 0xa495, 
    magic_ttprogressbar = 0xe495, 
    magic_ttscrollpane = 0x695, 
    magic_ttwindow = 0x895, 
    magic_ttframe = 0x1895, 
    magic_ttscroller = 0x2895, 
    magic_ttmenuitem = 0xd5, 
    magic_ttcheckmenuitem = 0x2d5, 
    magic_ttradiomenuitem = 0xad5, 
    magic_ttmenu = 0x4d5, 
    magic_ttmenubar = 0x115, 
    magic_ttanytext = 0x3895, 
    magic_tttextfield = 0x7895, 
    magic_tttextarea = 0xf895, 
    magic_tttheme = 0x25, 
    magic_ttapplication = 0x2d,

    magic_last
} e_magic_ttobj;


/* #define IS(xxx,o) macros */
#define IS(obj,o) (((o)->FN->magic & magicmask_(obj)) == magic_(obj))







typedef enum e_order_fields {

    ttobj_field_first,            
    ttobj_id,    
    ttobj_refcount,    
    ttobj_oflags,            
    ttobj_user_data,    
    ttobj_events_inprogress,    
    ttobj_events_informed,
    ttobj_field_last,
  
    ttevent_field_first,        
    ttevent_callback,    
    ttevent_component,    
    ttevent_evtype,    
    ttevent_evcode,    
    ttevent_evflags,            
    ttevent_field_last,
 
    tteventbig_field_first,        
    tteventbig_x,    
    tteventbig_y,    
    tteventbig_w,    
    tteventbig_h,    
    tteventbig_value,    
    tteventbig_old_value,    
    tteventbig_len,    
    tteventbig_data,
    tteventbig_field_last,
 
    ttbitmask_field_first,                    
    ttbitmask_field_last,
 
    tteventmask_field_first,        
    tteventmask_evtype_mask,    
    tteventmask_evcode_mask,    
    tteventmask_component_mask,    
    tteventmask_truth_table,
    tteventmask_field_last,
 
    ttcallback_field_first,        
    ttcallback_lflags,    
    ttcallback_component,    
    ttcallback_prev,    
    ttcallback_next,
    ttcallback_field_last,
 
    ttlistener_field_first,            
    ttlistener_event,    
    ttlistener_narg_component,    
    ttlistener_narg_event,    
    ttlistener_nargs,    
    ttlistener_function,    
    ttlistener_args,    
    ttlistener_event_mask,        
    ttlistener_field_last,
 
    tttimer_field_first,                    
    tttimer_field_last,
 
    ttcomponent_field_first,        
    ttcomponent_callbacks,    
    ttcomponent_listeners,    
    ttcomponent_timers,    
    ttcomponent_datas,
    ttcomponent_field_last,
 
    ttdata_field_first,            
    ttdata_component,    
    ttdata_key,    
    ttdata_key_len,    
    ttdata_data,
    ttdata_field_last,
 
    ttvisible_field_first,        
    ttvisible_vflags,    
    ttvisible_prev,    
    ttvisible_next,    
    ttvisible_parent,    
    ttvisible_child_first,    
    ttvisible_child_last,    
    ttvisible_theme,    
    ttvisible_repaint,
    ttvisible_field_last,
 
    ttnative_field_first,    
    ttnative_field_last,
 
    ttwidget_field_first,        
    ttwidget_x,    
    ttwidget_y,    
    ttwidget_w,    
    ttwidget_h,    
    ttwidget_xl,    
    ttwidget_yl,    
    ttwidget_wl,    
    ttwidget_hl,        
    ttwidget_tooltip,
    ttwidget_field_last,
 
    ttlabel_field_first,        
    ttlabel_text_len,    
    ttlabel_text,
    ttlabel_field_last,
 
    tttooltip_field_first,            
    tttooltip_widget,    
    tttooltip_field_last,
 
    ttbuttongroup_field_first,        
    ttbuttongroup_group_first,    
    ttbuttongroup_group_last,    
    ttbuttongroup_checked,
    ttbuttongroup_field_last,
 
    ttanybutton_field_first,        
    ttanybutton_text,    
    ttanybutton_text_width,    
    ttanybutton_text_height,    
    ttanybutton_field_last,
 
    ttbutton_field_first,    
    ttbutton_field_last,
 
    ttcheckbutton_field_first,    
    ttcheckbutton_field_last,
 
    ttradiobutton_field_first,        
    ttradiobutton_group,    
    ttradiobutton_group_prev,    
    ttradiobutton_group_next,
    ttradiobutton_field_last,
 
    ttanyscroll_field_first,        
    ttanyscroll_orientation,    
    ttanyscroll_size,    
    ttanyscroll_real_size,    
    ttanyscroll_view_size,        
    ttanyscroll_position,    
    ttanyscroll_real_position,    
    ttanyscroll_field_last,
 
    ttscrollbar_field_first,        
    ttscrollbar_field_last,
 
    ttslider_field_first,        
    ttslider_slide_min,    
    ttslider_slide_max,    
    ttslider_slide_value,
    ttslider_field_last,
 
    ttprogressbar_field_first,            
    ttprogressbar_field_last,
 
    ttscrollpane_field_first,        
    ttscrollpane_bar_x,    
    ttscrollpane_bar_y,
    ttscrollpane_field_last,
 
    ttwindow_field_first,        
    ttwindow_title_len,    
    ttwindow_title,
    ttwindow_field_last,
 
    ttframe_field_first,        
    ttframe_menubar,
    ttframe_field_last,
 
    ttscroller_field_first,        
    ttscroller_scrollpane,
    ttscroller_field_last,
 
    ttmenuitem_field_first,        
    ttmenuitem_name,
    ttmenuitem_field_last,
 
    ttcheckmenuitem_field_first,    
    ttcheckmenuitem_field_last,
 
    ttradiomenuitem_field_first,    
    ttradiomenuitem_field_last,
 
    ttmenu_field_first,    
    
    ttmenu_menubar,
    ttmenu_field_last,
 
    ttmenubar_field_first,    
    ttmenubar_field_last,
 
    ttanytext_field_first,        
    ttanytext_text_len,    
    ttanytext_text,
    ttanytext_field_last,
 
    tttextfield_field_first,    
    tttextfield_field_last,
 
    tttextarea_field_first,    
    tttextarea_field_last,
 
    tttheme_field_first,    
    
    tttheme_name,                
    tttheme_field_last,
 
    ttapplication_field_first,        
    ttapplication_name,
    ttapplication_field_last,

    ttobj_field_max
} e_order_fields;



#endif /* _TT_TREEM4_H */
