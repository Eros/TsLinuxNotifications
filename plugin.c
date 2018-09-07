//
// Created by george on 06/09/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "include/public_errors.h"
#include "include/public_definitions.h"
#include "include/public_errors_rare.h"
#include "include/public_rare_definitions.h"
#include "include/clientlib_publicdefinitions.h"
#include "include/ts3_functions.h"

static struct TS3Functions ts3Functions;

#define _strcpy(dest, destSize, src) {
    strncpy(dest, src, destSize - 1); \ (dest)[destSize - 1] = '\0';
}
#define PLUGIN_API_VERSION 22

#define PATH_BUFSIZE 512
#define COMMAND_BUFSIZE 128
#define INFODATA_BUFSIZE 128
#define SERVERINFO_BUFSIZE 256
#define CHANNELINFO_BUFSIZE 512
#define RETURNCODE_BUFSIZE 128

static char* pluginID = NULL;

int current_client(uint64 serverConnectionHandlerID, anyID other,
                   anyID *client);

int current_channel(uint64 serverConnectionHandlerID, uint64 other,
                    uint64 *current);

void send_server_message_notification(uint64 serverConnectionHandlerID,
                                      const char *fromName, const char *message);

void send_channel_message_notification(uint64 serverConnectionHandlerID,
                                       anyID clientID, const char *fromName, const char *message);

void show_welcome_message();

const char* ts3plugin_name(){ return "TsLinuxNotifications"; }

const char* ts3plugin_version(){ return "1.0-BETA"; }

const int ts3plugin_apiVersion() { return PLUGIN_API_VERSION; }

void shutdown(){
    if(pluginID){
        free(pluginID);
        pluginID = NULL;
    }
}

void ts3plugin_onUpdateChannelEditEvent(uint64 serverConnecctionHandlerID, uint64 channelID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier){
    uint64 currentID;

    if(current_client(serverConnecctionHandlerID, invokerID, (anyID *) &currentID) != 1 && (current_channel(serverConnecctionHandlerID, channelID, &currentID) == 1)){
        send_server_message_notification(serverConnecctionHandlerID, (const char *) currentID, "todo, replace this shit");
    }
}