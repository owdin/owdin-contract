#pragma once

#include "define.hpp"
#include "models/config_index/config_index.hpp"

using namespace std;
using namespace eosio;

namespace owdin {
    class owdin_config {
        private:
            account_name self;


        public:
            owdin_config( account_name _self ): self( _self ) { };

            void set( account_name account, string playbook, string playhash, uint8_t object_type ) {
                time current_time = now();
                configsIndex configs( self, account );

                auto itr = configs.find( account );
                eosio_assert( itr != configs.end(), "can not found account" );

                if (object_type == OBJECT_STORAGE ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.ipfs_receiver = account;
                        s.ipfs_conf = playbook;
                        s.ipfs_hash = playhash;
                        s.ipfs_update = current_time;
                    });
                } else if (object_type == OBJECT_NETWORK ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.net_receiver = account;
                        s.net_conf = playbook;
                        s.net_hash = playhash;
                        s.net_update = current_time;
                    });
                } else if (object_type == OBJECT_SYSTEM ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sys_receiver = account;
                        s.sys_conf = playbook;
                        s.sys_hash = playhash;
                        s.sys_update = current_time;
                    });
                } else if (object_type == OBJECT_PROCESS ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.proc_receiver = account;
                        s.proc_conf = playbook;
                        s.proc_hash = playhash;
                        s.proc_update = current_time;
                    });
                } else if (object_type == OBJECT_SECURITY ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sec_receiver = account;
                        s.sec_conf = playbook;
                        s.sec_hash = playhash;
                        s.sec_update = current_time;
                    });
                } else {
                    eosio_assert( false, "object type error" );
                }
            }

            void remove( account_name account, uint8_t object_type ) {
                configsIndex configs( self, account );

                auto itr = configs.find( account );
                eosio_assert( itr != configs.end(), "can not found account" );

                configs.erase( itr );
            }

            void initial( account_name account, uint8_t object_type ) {
                time current_time = now();
                configsIndex configs( self, account );

                auto itr = configs.find( account );
                eosio_assert( itr != configs.end(), "can not found account" );

                configs.modify( itr, self, [&]( auto& s ) {
                    s.ipfs_receiver = account;
                    s.proc_receiver = self;
                    s.sys_receiver = self;
                    s.net_receiver = self;
                    s.sec_receiver = self;
                    s.ipfs_conf = "";
                    s.proc_conf = "";
                    s.ipfs_hash = "";
                    s.proc_hash = "";
                    s.sys_conf = "";
                    s.sys_hash = "";
                    s.net_conf = "";
                    s.net_hash = "";
                    s.sec_conf = "";
                    s.sec_hash = "";
                    s.ipfs_update = current_time;
                    s.proc_update = current_time;
                    s.sys_update = current_time;
                    s.net_update = current_time;
                    s.sec_update = current_time;
                    s.created = current_time;
                });
            }

            void clear( account_name account, uint8_t object_type ) {
                time current_time = now();
                configsIndex configs( self, account );

                auto itr = configs.find( account );
                eosio_assert( itr != configs.end(), "can not found account" );

                if (object_type == OBJECT_STORAGE ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.ipfs_receiver = self;
                        s.ipfs_conf = "";
                        s.ipfs_hash = "";
                        s.ipfs_update = current_time;
                    });
                } else if (object_type == OBJECT_NETWORK ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.net_receiver = self;
                        s.net_conf = "";
                        s.net_hash = "";
                        s.net_update = current_time;
                    });
                } else if (object_type == OBJECT_SYSTEM ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sys_receiver = self;
                        s.sys_conf = "";
                        s.sys_hash = "";
                        s.sys_update = current_time;
                    });
                } else if (object_type == OBJECT_PROCESS ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.proc_receiver = self;
                        s.proc_conf = "";
                        s.proc_hash = "";
                        s.proc_update = current_time;
                    });
                } else if (object_type == OBJECT_SECURITY ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sec_receiver = self;
                        s.sec_conf = "";
                        s.sec_hash = "";
                        s.sec_update = current_time;
                    });
                } else {
                    eosio_assert( false, "object type error" );
                }
            }

            void update( account_name account, string stat, uint8_t object_type ) {
                time current_time = now();
                configsIndex configs( self, account );

                auto itr = configs.find( account );
                eosio_assert( itr != configs.end(), "can not found account" );

                if (object_type == OBJECT_STORAGE ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.ipfs_receiver = self;
                        s.ipfs_status = stat;
                        s.ipfs_update = current_time;
                    });
                } else if (object_type == OBJECT_NETWORK ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.net_receiver = self;
                        s.net_status = stat;
                        s.net_update = current_time;
                    });
                } else if (object_type == OBJECT_SYSTEM ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sys_receiver = self;
                        s.sys_status = stat;
                        s.sys_update = current_time;
                    });
                } else if (object_type == OBJECT_PROCESS ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.proc_receiver = self;
                        s.proc_status = stat;
                        s.proc_update = current_time;
                    });
                } else if (object_type == OBJECT_SECURITY ) {
                    configs.modify( itr, self, [&]( auto& s ) {
                        s.sec_receiver = self;
                        s.sec_status = stat;
                        s.sec_update = current_time;
                    });
                } else {
                    eosio_assert( false, "object type error" );
                }
            }
    };
}