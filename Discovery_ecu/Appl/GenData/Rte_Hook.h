/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Hook.h
 *        Config:  discovery_ecu.dpa"
 *   ECU-Project:  P2P
 *
 *     Generator:  MICROSAR RTE Generator Version 4.14.0
 *                 RTE Core Version 1.14.0
 *       License:  Unlimited license CBD1800319 for Tong Ji University
 *
 *   Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 * Not configured:
 *
 *  Rte_ReadHook_BswM_Request_ESH_PostRunRequest_0_requestedMode_Return
 *  Rte_ReadHook_BswM_Request_ESH_PostRunRequest_0_requestedMode_Start
 *  Rte_ReadHook_BswM_Request_ESH_PostRunRequest_1_requestedMode_Return
 *  Rte_ReadHook_BswM_Request_ESH_PostRunRequest_1_requestedMode_Start
 *  Rte_ReadHook_BswM_Request_ESH_RunRequest_0_requestedMode_Return
 *  Rte_ReadHook_BswM_Request_ESH_RunRequest_0_requestedMode_Start
 *  Rte_ReadHook_BswM_Request_ESH_RunRequest_1_requestedMode_Return
 *  Rte_ReadHook_BswM_Request_ESH_RunRequest_1_requestedMode_Start
 *  Rte_Runnable_BswM_BswM_MainFunction_Return
 *  Rte_Runnable_BswM_BswM_MainFunction_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_1_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_1_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_2_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_2_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_3_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_3_Start
 *  Rte_Runnable_ComM_GetCurrentComMode_Return
 *  Rte_Runnable_ComM_GetCurrentComMode_Start
 *  Rte_Runnable_ComM_GetInhibitionStatus_Return
 *  Rte_Runnable_ComM_GetInhibitionStatus_Start
 *  Rte_Runnable_ComM_GetMaxComMode_Return
 *  Rte_Runnable_ComM_GetMaxComMode_Start
 *  Rte_Runnable_ComM_GetRequestedComMode_Return
 *  Rte_Runnable_ComM_GetRequestedComMode_Start
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Return
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Start
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Return
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Start
 *  Rte_Runnable_ComM_PreventWakeUp_Return
 *  Rte_Runnable_ComM_PreventWakeUp_Start
 *  Rte_Runnable_ComM_ReadInhibitCounter_Return
 *  Rte_Runnable_ComM_ReadInhibitCounter_Start
 *  Rte_Runnable_ComM_RequestComMode_Return
 *  Rte_Runnable_ComM_RequestComMode_Start
 *  Rte_Runnable_ComM_ResetInhibitCounter_Return
 *  Rte_Runnable_ComM_ResetInhibitCounter_Start
 *  Rte_Runnable_ComM_SetECUGroupClassification_Return
 *  Rte_Runnable_ComM_SetECUGroupClassification_Start
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Return
 *  Rte_Runnable_Dcm_Dcm_MainFunction_Start
 *  Rte_Runnable_Dcm_GetActiveProtocol_Return
 *  Rte_Runnable_Dcm_GetActiveProtocol_Start
 *  Rte_Runnable_Dcm_GetRequestKind_Return
 *  Rte_Runnable_Dcm_GetRequestKind_Start
 *  Rte_Runnable_Dcm_GetSesCtrlType_Return
 *  Rte_Runnable_Dcm_GetSesCtrlType_Start
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Return
 *  Rte_Runnable_Dcm_ResetToDefaultSession_Start
 *  Rte_Runnable_Dcm_SetActiveDiagnostic_Return
 *  Rte_Runnable_Dcm_SetActiveDiagnostic_Start
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Return
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Start
 *  Rte_Runnable_EcuM_GetBootTarget_Return
 *  Rte_Runnable_EcuM_GetBootTarget_Start
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetShutdownCause_Return
 *  Rte_Runnable_EcuM_GetShutdownCause_Start
 *  Rte_Runnable_EcuM_GetShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetShutdownTarget_Start
 *  Rte_Runnable_EcuM_SelectBootTarget_Return
 *  Rte_Runnable_EcuM_SelectBootTarget_Start
 *  Rte_Runnable_EcuM_SelectShutdownCause_Return
 *  Rte_Runnable_EcuM_SelectShutdownCause_Start
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Return
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Start
 *  Rte_Runnable_Os_OsCore_Core0_swc_GetCounterValue_Return
 *  Rte_Runnable_Os_OsCore_Core0_swc_GetCounterValue_Start
 *  Rte_Runnable_Os_OsCore_Core0_swc_GetElapsedValue_Return
 *  Rte_Runnable_Os_OsCore_Core0_swc_GetElapsedValue_Start
 *  Rte_Runnable_Os_OsCore_Core1_swc_GetCounterValue_Return
 *  Rte_Runnable_Os_OsCore_Core1_swc_GetCounterValue_Start
 *  Rte_Runnable_Os_OsCore_Core1_swc_GetElapsedValue_Return
 *  Rte_Runnable_Os_OsCore_Core1_swc_GetElapsedValue_Start
 *  Rte_Runnable_Os_OsCore_Core2_swc_GetCounterValue_Return
 *  Rte_Runnable_Os_OsCore_Core2_swc_GetCounterValue_Start
 *  Rte_Runnable_Os_OsCore_Core2_swc_GetElapsedValue_Return
 *  Rte_Runnable_Os_OsCore_Core2_swc_GetElapsedValue_Start
 *  Rte_Runnable_cycle_task_Core0_Task_1ms_Return
 *  Rte_Runnable_cycle_task_Core0_Task_1ms_Start
 *  Rte_Runnable_disc_ecu_Core0_Task_100ms_Return
 *  Rte_Runnable_disc_ecu_Core0_Task_100ms_Start
 *  Rte_Runnable_disc_ecu_Core0_Task_10ms_Return
 *  Rte_Runnable_disc_ecu_Core0_Task_10ms_Start
 *  Rte_Runnable_disc_ecu_Core0_Task_20ms_Return
 *  Rte_Runnable_disc_ecu_Core0_Task_20ms_Start
 *  Rte_Runnable_disc_ecu_Core0_Task_50ms_Return
 *  Rte_Runnable_disc_ecu_Core0_Task_50ms_Start
 *  Rte_SwitchHook_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Return
 *  Rte_SwitchHook_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Start
 *  Rte_SwitchHook_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_Return
 *  Rte_SwitchHook_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_DcmCommunicationControl_ComMConf_ComMChannel_CAN00_f26020e5_Start
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Return
 *  Rte_SwitchHook_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Start
 *  Rte_Task_Activate
 *  Rte_Task_Dispatch
 *  Rte_Task_WaitEvent
 *  Rte_Task_WaitEventRet
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanTrcv_30_Tja1043_CANTRCV_30_TJA1043_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanTrcv_30_Tja1043_CANTRCV_30_TJA1043_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_EnterHook_Dcm_DCM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Dcm_DCM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_Ccu6IenUpdate_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_Ccu6IenUpdate_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_CcuInterruptHandle_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_CcuInterruptHandle_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_CcuVariableupdate_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_CcuVariableupdate_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_EnableNotification_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_EnableNotification_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_EnableWakeup_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_EnableWakeup_Start
 *  SchM_EnterHook_Icu_17_GtmCcu6_ResetEdgeCount_Return
 *  SchM_EnterHook_Icu_17_GtmCcu6_ResetEdgeCount_Start
 *  SchM_EnterHook_LinIf_LINIF_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_LinIf_LINIF_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_LinIf_LINIF_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_LinIf_LINIF_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_LinSM_LINSM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Spi_AsyncTransmit_Return
 *  SchM_EnterHook_Spi_AsyncTransmit_Start
 *  SchM_EnterHook_Spi_Cancel_Return
 *  SchM_EnterHook_Spi_Cancel_Start
 *  SchM_EnterHook_Spi_DeInit_Return
 *  SchM_EnterHook_Spi_DeInit_Start
 *  SchM_EnterHook_Spi_GetSequenceResult_Return
 *  SchM_EnterHook_Spi_GetSequenceResult_Start
 *  SchM_EnterHook_Spi_Init_Return
 *  SchM_EnterHook_Spi_Init_Start
 *  SchM_EnterHook_Spi_SyncTransmit_Return
 *  SchM_EnterHook_Spi_SyncTransmit_Start
 *  SchM_EnterHook_Spi_WriteIB_Return
 *  SchM_EnterHook_Spi_WriteIB_Start
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanTp_CANTP_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanTrcv_30_Tja1043_CANTRCV_30_TJA1043_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanTrcv_30_Tja1043_CANTRCV_30_TJA1043_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_ExitHook_Dcm_DCM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Dcm_DCM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_Ccu6IenUpdate_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_Ccu6IenUpdate_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_CcuInterruptHandle_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_CcuInterruptHandle_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_CcuVariableupdate_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_CcuVariableupdate_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_EnableNotification_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_EnableNotification_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_EnableWakeup_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_EnableWakeup_Start
 *  SchM_ExitHook_Icu_17_GtmCcu6_ResetEdgeCount_Return
 *  SchM_ExitHook_Icu_17_GtmCcu6_ResetEdgeCount_Start
 *  SchM_ExitHook_LinIf_LINIF_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_LinIf_LINIF_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_LinIf_LINIF_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_LinIf_LINIF_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_LinSM_LINSM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Spi_AsyncTransmit_Return
 *  SchM_ExitHook_Spi_AsyncTransmit_Start
 *  SchM_ExitHook_Spi_Cancel_Return
 *  SchM_ExitHook_Spi_Cancel_Start
 *  SchM_ExitHook_Spi_DeInit_Return
 *  SchM_ExitHook_Spi_DeInit_Start
 *  SchM_ExitHook_Spi_GetSequenceResult_Return
 *  SchM_ExitHook_Spi_GetSequenceResult_Start
 *  SchM_ExitHook_Spi_Init_Return
 *  SchM_ExitHook_Spi_Init_Start
 *  SchM_ExitHook_Spi_SyncTransmit_Return
 *  SchM_ExitHook_Spi_SyncTransmit_Start
 *  SchM_ExitHook_Spi_WriteIB_Return
 *  SchM_ExitHook_Spi_WriteIB_Start
 *  SchM_Schedulable_BswM_BswM_MainFunction_Return
 *  SchM_Schedulable_BswM_BswM_MainFunction_Start
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Return
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Start
 *  SchM_Schedulable_CanTp_CanTp_MainFunction_Return
 *  SchM_Schedulable_CanTp_CanTp_MainFunction_Start
 *  SchM_Schedulable_CanTrcv_30_Tja1043_CanTrcv_30_Tja1043_MainFunction_Return
 *  SchM_Schedulable_CanTrcv_30_Tja1043_CanTrcv_30_Tja1043_MainFunction_Start
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Return
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_1_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_1_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_2_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_2_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_3_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_3_Start
 *  SchM_Schedulable_Com_Com_MainFunctionRx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionRx_Start
 *  SchM_Schedulable_Com_Com_MainFunctionTx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionTx_Start
 *  SchM_Schedulable_Dcm_Dcm_MainFunction_Return
 *  SchM_Schedulable_Dcm_Dcm_MainFunction_Start
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Return
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Start
 *  SchM_Schedulable_LinIf_LinIf_MainFunction_Return
 *  SchM_Schedulable_LinIf_LinIf_MainFunction_Start
 *  SchM_Schedulable_LinSM_LinSM_MainFunction_Return
 *  SchM_Schedulable_LinSM_LinSM_MainFunction_Start
 *  SchM_Schedulable_Rte_Rte_ComSendSignalProxyPeriodic_Return
 *  SchM_Schedulable_Rte_Rte_ComSendSignalProxyPeriodic_Start
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Return
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HOOK_H
# define _RTE_HOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

#endif /* _RTE_HOOK_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
