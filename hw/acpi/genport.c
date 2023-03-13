/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Generic Port device implementation
 *
 * Copyright (C) 2023 Intel Corporation
 */
#include "qemu/osdep.h"
#include "hw/qdev-properties.h"
#include "qapi/error.h"
#include "qapi/visitor.h"
#include "qom/object_interfaces.h"
#include "hw/qdev-core.h"

#define TYPE_GENERIC_PORT_DEVICE "genport"

#define GENPORT_NUMA_NODE_PROP "node"
#define GENPORT_DEV_PROP       "genport"

typedef struct GenPortDevice {
    /* private */
    DeviceState parent_obj;

    /* public */
    uint32_t node;
} GenPortDevice;

static Property genport_properties[] = {
    DEFINE_PROP_UINT32(GENPORT_NUMA_NODE_PROP, GenPortDevice, node, 0),
    DEFINE_PROP_END_OF_LIST(),
};

static void genport_realize(DeviceState *dev, Error **errp)
{
	printf("XXX %s called\n", __func__);
}

static void genport_unrealize(DeviceState *dev)
{

}

static void generic_port_class_init(ObjectClass *oc, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(oc);

    dc->hotpluggable = false;
    dc->desc = "Generic Port";
    dc->user_creatable = true;
    dc->realize = genport_realize;
    dc->unrealize = genport_unrealize;
    device_class_set_props(dc, genport_properties);
}

static const TypeInfo generic_port_device_info = {
    .name = TYPE_GENERIC_PORT_DEVICE,
    .parent = TYPE_DEVICE,
    .instance_size = sizeof(GenPortDevice),
    .class_init = generic_port_class_init,
    .class_size = sizeof(DeviceClass),
    .interfaces = (InterfaceInfo[]){
	    { TYPE_USER_CREATABLE },
	    {} },
};

static void generic_port_register_types(void)
{
    type_register_static(&generic_port_device_info);
}

type_init(generic_port_register_types);
