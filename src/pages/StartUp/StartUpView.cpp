#include <stdarg.h>
#include <stdio.h>
#include "StartUpView.h"

using namespace Page;

void StartUpView::Create(lv_obj_t* root) {
#if defined(M5CORES3)
    ui.img_core_text = lv_img_create(root);
    lv_img_set_src(ui.img_core_text, ResourcePool::GetImage("core_text"));
    // lv_obj_align(ui.img_core_text, LV_ALIGN_CENTER, 0, -40);
    lv_obj_set_pos(ui.img_core_text, 78, -40);
    ui.img_s3_text = lv_img_create(root);
    lv_img_set_src(ui.img_s3_text, ResourcePool::GetImage("s3_text"));
    // lv_obj_align(ui.img_s3_text, LV_ALIGN_CENTER, 0, 340);
    lv_obj_set_pos(ui.img_s3_text, 78, 340);

    ui.anim_timeline                     = lv_anim_timeline_create();
    lv_anim_timeline_wrapper_t wrapper[] = {
    ANIM_DEF(0, ui.img_core_text, y, -40, 45, 800),
    ANIM_DEF(0, ui.img_s3_text, y, 340, 90, 800),
    LV_ANIM_TIMELINE_WRAPPER_END};
    lv_anim_timeline_add_wrapper(ui.anim_timeline, wrapper);
    ui.img_cores3_diagram = lv_img_create(root);
    lv_img_set_src(ui.img_cores3_diagram,
                ResourcePool::GetImage("cores3_diagram"));
    lv_obj_align(ui.img_cores3_diagram, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(ui.img_cores3_diagram, LV_OBJ_FLAG_HIDDEN);
#elif defined(M5CORES3SE)
    ui.img_core_text_se = lv_img_create(root);
    lv_img_set_src(ui.img_core_text_se, ResourcePool::GetImage("core_text_se"));
    // lv_obj_align(ui.img_core_text, LV_ALIGN_CENTER, 0, -40);
    lv_obj_set_pos(ui.img_core_text_se, 78, -40);
    ui.img_s3_text_se = lv_img_create(root);
    lv_img_set_src(ui.img_s3_text_se, ResourcePool::GetImage("s3_text_se"));
    // lv_obj_align(ui.img_s3_text, LV_ALIGN_CENTER, 0, 340);
    lv_obj_set_pos(ui.img_s3_text_se, 78, 340);

    ui.anim_timeline                     = lv_anim_timeline_create();
    lv_anim_timeline_wrapper_t wrapper[] = {
    ANIM_DEF(0, ui.img_core_text_se, y, -40, 45, 800),
    ANIM_DEF(0, ui.img_s3_text_se, y, 340, 90, 800),
    LV_ANIM_TIMELINE_WRAPPER_END};

    lv_anim_timeline_add_wrapper(ui.anim_timeline, wrapper);
    ui.img_cores3_diagram_se = lv_img_create(root);
    lv_img_set_src(ui.img_cores3_diagram_se,
                ResourcePool::GetImage("cores3_diagram_se"));
    lv_obj_align(ui.img_cores3_diagram_se, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(ui.img_cores3_diagram_se, LV_OBJ_FLAG_HIDDEN);
#endif
}

void StartUpView::Delete()
{
    if(ui.anim_timeline)
    {
        lv_anim_timeline_del(ui.anim_timeline);
        ui.anim_timeline = nullptr;
    }
}
