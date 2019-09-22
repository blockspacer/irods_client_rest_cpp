/**
* iRODS REST API
* This is the iRODS REST API
*
* OpenAPI spec version: 1.0.0
* Contact: info@irods.org
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/swagger-api/swagger-codegen.git
* Do not edit the class manually.
*/
/*
 * StreamApi.h
 *
 * 
 */

#ifndef StreamApi_H_
#define StreamApi_H_


#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/http_headers.h>
#include <pistache/optional.h>
#include "ModelBase.h"

#include <string>

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

class  StreamApi {
public:
    StreamApi(Pistache::Address addr);
    virtual ~StreamApi() {};
    void init(size_t thr);
    void start();
    void shutdown();

    const std::string base = "/jasoncoposky/irods-rest/1.0.0";

private:
    void setupRoutes();

    void stream_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);
    void stream_api_default_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response);

    std::shared_ptr<Pistache::Http::Endpoint> httpEndpoint;
    Pistache::Rest::Router router;


    /// <summary>
    /// streams bytes to/from a data thinger
    /// </summary>
    /// <remarks>
    /// Obtains an HTTP stream of file bytes 
    /// </remarks>
    /// <param name="path">irods absolute logical path to the file</param>
    /// <param name="offset">number of bytes to skip for pagination (optional)</param>
    /// <param name="limit">maximum number of bytes to return (optional)</param>
    virtual void stream(const Pistache::Optional<std::string> &path, const Pistache::Optional<std::string> &offset, const Pistache::Optional<std::string> &limit, Pistache::Http::ResponseWriter &response) = 0;

};

}
}
}
}

#endif /* StreamApi_H_ */
