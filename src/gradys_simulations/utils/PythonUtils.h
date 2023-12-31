#ifndef gradys_simulations_PYTHON_UTILS_H_
#define gradys_simulations_PYTHON_UTILS_H_

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "gradys_simulations/protocols/messages/network/PythonMessage_m.h"
#include "pybind11_json/pybind11_json.hpp"
#include "nlohmann/json.hpp"

using namespace pybind11::literals;

namespace py = pybind11;

namespace gradys_simulations {

static CommunicationCommand* transformToCommunicationCommandPython(
        py::object comm_command) {

    nlohmann::json jsonMessage = nlohmann::json::parse(
            comm_command.attr("message").cast<std::string>());

    // Create communication command
    CommunicationCommand *command = new CommunicationCommand();

    py::object CommunicationCommandTypePython = py::module_::import(
            "simulator.messages.communication").attr(
            "CommunicationCommandType");

    py::object ctl = CommunicationCommandTypePython(
            comm_command.attr("command").cast<int>());

    if (ctl.is(CommunicationCommandTypePython.attr("SEND"))) {
        command->setCommandType(CommunicationCommandType::SEND_MESSAGE);

    } else if (ctl.is(CommunicationCommandTypePython.attr("BROADCAST"))) {
        command->setCommandType(CommunicationCommandType::SET_TARGET);

    } else {
        std::cout
                << "Something is wrong in transformToCommunicationCommandPython"
                << std::endl;
        exit(1);
    }

    // Create payload
    PythonMessage *payload = new PythonMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setInformation(jsonMessage.dump());

    command->setPayloadTemplate(payload);

    return command;
}

static MobilityCommand* transformToMobilityCommandPython(
        py::object mob_command) {

    // Create mobility command
    MobilityCommand *command = new MobilityCommand();

    py::object MobilityCommandTypePython = py::module_::import(
            "simulator.messages.mobility").attr("MobilityCommandType");

    py::object ctl = MobilityCommandTypePython(
            mob_command.attr("command").cast<int>());
    if (ctl.is(MobilityCommandTypePython.attr("SET_MODE"))) {
        command->setCommandType(MobilityCommandType::IDLE_TIME);

    } else if (ctl.is(MobilityCommandTypePython.attr("GOTO_COORDS"))) {
        command->setCommandType(MobilityCommandType::GOTO_COORDS);

    } else if (ctl.is(MobilityCommandTypePython.attr("GOTO_WAYPOINT"))) {
        command->setCommandType(MobilityCommandType::GOTO_WAYPOINT);

    } else if (ctl.is(MobilityCommandTypePython.attr("REVERSE"))) {
        command->setCommandType(MobilityCommandType::REVERSE);

    } else {
        std::cout << "Something is wrong in transformToMobilityCommandPython"
                << std::endl;
        exit(1);
    }

    command->setParam1(mob_command.attr("param_1").cast<int>());
    command->setParam2(mob_command.attr("param_2").cast<int>());
    command->setParam3(mob_command.attr("param_3").cast<int>());
    command->setParam4(mob_command.attr("param_4").cast<int>());
    command->setParam5(mob_command.attr("param_5").cast<int>());

    return command;
}

static std::string concatenate(const std::string &str, int num) {
    std::string numStr = std::to_string(num);

    return str + "_for_" + numStr;
}

}

#endif /* gradys_simulations_PYTHON_UTILS_H_ */
