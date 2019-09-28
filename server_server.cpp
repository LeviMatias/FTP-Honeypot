//
// Created by Matias on 26/09/2019.
//

#include "server_server.h"

void server_server::Serve() {
    MakeDirCmd mkd;
    ListCmd list;//TODO READ CONFIG AND MAKE STATIC CMD EXEC
    interpreter.AddCommand("MKD", &mkd);
    interpreter.AddCommand("LIST", &list);
}
