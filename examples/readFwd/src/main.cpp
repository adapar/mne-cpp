//=============================================================================================================
/**
* @file     main.cpp
* @author   Christoph Dinh <christoph.dinh@live.de>;
* @version  1.0
* @date     September, 2012
*
* @section  LICENSE
*
* Copyright (C) 2010 Christoph Dinh. All rights reserved.
*
* No part of this program may be photocopied, reproduced,
* or translated to another program language without the
* prior written consent of the author.
*
*
* @brief    Implements the main() application function.
*
*/


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include <iostream>
#include <vector>

#include "../../../MNE/mne/mne.h"


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================
//#include <QDebug>
//#include <QDir>
//#include <QPluginLoader>

#include <QtCore/QCoreApplication>

//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace MNELIB;


//*************************************************************************************************************
//=============================================================================================================
// MAIN
//=============================================================================================================

//=============================================================================================================
/**
* The function main marks the entry point of the program.
* By default, main has the storage class extern.
*
* @param [in] argc (argument count) is an integer that indicates how many arguments were entered on the command line when the program was started.
* @param [in] argv (argument vector) is an array of pointers to arrays of character objects. The array objects are null-terminated strings, representing the arguments that were entered on the command line when the program was started.
* @return the value that was set to exit() (which is 0 if exit() is called via quit()).
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MNEForwardSolution* t_ForwardSolution = NULL;

    QString t_sFile = "./MNE-sample-data/MEG/sample/sample_audvis-meg-eeg-oct-6-fwd.fif";
    if(MNE::read_forward_solution(t_sFile, t_ForwardSolution))
    {
        std::cout << std::endl << "first 10 rows and columns of the Gain Matrix:" << std::endl << t_ForwardSolution->sol->data.block(0,0,10,10) << std::endl;
        std::cout << std::endl << "first 10 dipole coordinates:" << std::endl << t_ForwardSolution->source_rr.block(0,0,10,3) << std::endl ;
    }

    return a.exec();
}

//*************************************************************************************************************
//=============================================================================================================
// STATIC DEFINITIONS
//=============================================================================================================


