
#include "qemu/osdep.h"
#include "qapi/qapi-commands-cxl.h"

void qmp_cxl_inject_gen_media_event(const char *path, CxlEventLog log,
                                    uint8_t flags, uint64_t physaddr,
                                    uint8_t descriptor, uint8_t type,
                                    uint8_t transaction_type,
                                    bool has_channel, uint8_t channel,
                                    bool has_rank, uint8_t rank,
                                    bool has_device, uint32_t device,
                                    const char *component_id,
                                    Error **errp) {}

void qmp_cxl_inject_dram_event(const char *path, CxlEventLog log, uint8_t flags,
                               uint64_t physaddr, uint8_t descriptor,
                               uint8_t type, uint8_t transaction_type,
                               bool has_channel, uint8_t channel,
                               bool has_rank, uint8_t rank,
                               bool has_nibble_mask, uint32_t nibble_mask,
                               bool has_bank_group, uint8_t bank_group,
                               bool has_bank, uint8_t bank,
                               bool has_row, uint32_t row,
                               bool has_column, uint16_t column,
                               bool has_correction_mask, uint64List *correction_mask,
                               Error **errp) {}

void qmp_cxl_inject_memory_module_event(const char *path, CxlEventLog log,
                                        uint8_t flags, uint8_t type,
                                        uint8_t health_status,
                                        uint8_t media_status,
                                        uint8_t additional_status,
                                        uint8_t life_used,
                                        int16_t temperature,
                                        uint32_t dirty_shutdown_count,
                                        uint32_t corrected_volatile_error_count,
                                        uint32_t corrected_persistent_error_count,
                                        Error **errp) {}

void qmp_cxl_inject_poison(const char *path, uint64_t start, uint64_t length,
                           Error **errp) {}

void qmp_cxl_inject_uncorrectable_errors(const char *path,
                                         CXLUncorErrorRecordList *errors,
                                         Error **errp) {}

void qmp_cxl_inject_correctable_error(const char *path, CxlCorErrorType type,
                                      Error **errp) {}
