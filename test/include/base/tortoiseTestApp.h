//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef TORTOISETESTAPP_H
#define TORTOISETESTAPP_H

#include "MooseApp.h"

class tortoiseTestApp;

template <>
InputParameters validParams<tortoiseTestApp>();

class tortoiseTestApp : public MooseApp
{
public:
  tortoiseTestApp(InputParameters parameters);
  virtual ~tortoiseTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* TORTOISETESTAPP_H */
