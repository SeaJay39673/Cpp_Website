#ifndef MyController_hpp
#define MyController_hpp

#include "dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/data/mapping/type/Primitive.hpp"
#include "oatpp/web/protocol/http/incoming/Request.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController
{
public:
    /**
     * Constructor with object mapper.
     * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
     */
    MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper)
    {
    }

public:
    ENDPOINT("GET", "/", root)
    {
        String s = oatpp::String::loadFromFile("./react-build/index.html");
        return createResponse(Status::CODE_200, s);
    }

    ENDPOINT("GET", "/static/*", staticFiles, REQUEST(std::shared_ptr<IncomingRequest>, request))
    {
        std::string tail = request->getPathTail();
        std::string path = "./react-build/static/" + tail;
        OATPP_LOGI("/static/*", " %s", path.c_str());
        String s = oatpp::String::loadFromFile(path.c_str());
        return createResponse(Status::CODE_200, s);
    }

    // TODO Insert Your endpoints here !!!
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif /* MyController_hpp */
