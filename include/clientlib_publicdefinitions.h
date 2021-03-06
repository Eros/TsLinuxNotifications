#ifndef CLIENTLIB_PUBLICDEFINITIONS_H
#define CLIENTLIB_PUBLICDEFINITIONS_H

enum Visibility {
    ENTER_VISIBILITY = 0,
    RETAIN_VISIBILITY,
    LEAVE_VISIBILITY
};

enum ConnectStatus {
    STATUS_DISCONNECTED = 0,
    STATUS_CONNECTING,
    STATUS_CONNECTED,
    STATUS_CONNECTION_ESTABLISHING,
    STATUS_CONNECTION_ESTABLISHED,
};

enum LocalTestMode {
    TEST_MODE_OFF = 0,
    TEST_MODE_VOICE_LOCAL_ONLY = 1,
    TEST_MODE_VOICE_LOCAL_AND_REMOTE = 2,
};

#endif //CLIENTLIB_PUBLICDEFINITIONS_H