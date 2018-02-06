//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "tortoiseTestApp.h"
#include "tortoiseApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<tortoiseTestApp>()
{
  InputParameters params = validParams<tortoiseApp>();
  return params;
}

tortoiseTestApp::tortoiseTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  tortoiseApp::registerObjectDepends(_factory);
  tortoiseApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  tortoiseApp::associateSyntaxDepends(_syntax, _action_factory);
  tortoiseApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  tortoiseApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    tortoiseTestApp::registerObjects(_factory);
    tortoiseTestApp::associateSyntax(_syntax, _action_factory);
    tortoiseTestApp::registerExecFlags(_factory);
  }
}

tortoiseTestApp::~tortoiseTestApp() {}

void
tortoiseTestApp::registerApps()
{
  registerApp(tortoiseApp);
  registerApp(tortoiseTestApp);
}

void
tortoiseTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
tortoiseTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
tortoiseTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
tortoiseTestApp__registerApps()
{
  tortoiseTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
tortoiseTestApp__registerObjects(Factory & factory)
{
  tortoiseTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
tortoiseTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  tortoiseTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
tortoiseTestApp__registerExecFlags(Factory & factory)
{
  tortoiseTestApp::registerExecFlags(factory);
}
