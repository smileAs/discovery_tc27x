<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output indent="yes"/>
	<!--
	-->
	<xsl:variable name="PluginNameDem" select="'AUTOSAR'"/>
	<xsl:variable name="PluginNameEcum" select="'AURIX'"/>
	<!--
	-->
	<!-- ##### Template to remove all MICROSAR components for Tresos Generation ##### -->
	<xsl:template match="*[(local-name()='MODULE-CONFIGURATION' or local-name()='ECUC-MODULE-CONFIGURATION-VALUES') and ./*[local-name()='DEFINITION-REF' and contains(text(),'/MICROSAR/')] and ./*[local-name()='DEFINITION-REF' and not (contains(text(),'/EcuM'))] and ./*[local-name()='DEFINITION-REF' and not (contains(text(),'/Dem'))]]"/>
	<xsl:template match="*[(local-name()='MODULE-CONFIGURATION' or local-name()='ECUC-MODULE-CONFIGURATION-VALUES') and ./*[local-name()='DEFINITION-REF' and contains(text(),'/AUTOSAR/')] and ./*[local-name()='DEFINITION-REF' and not (contains(text(),'/EcuM'))] and ./*[local-name()='DEFINITION-REF' and not (contains(text(),'/Dem'))]]"/>
	<!-- ##### Template to remove all ECUC-MODULE-CONFIGURATION-VALUESs except the Mcal relevant ##### -->
	<xsl:template match="*[local-name()='ECUC-MODULE-CONFIGURATION-VALUES' and ./*[local-name()='DEFINITION-REF' and not(contains(text(),'/AURIX/Resource'))  and not(contains(text(),'/Dem')) and not(contains(text(),'/EcuM')) and not(contains(text(),'/AURIX/Adc')) and not(contains(text(),'/AURIX/Dio')) and not(contains(text(),'/AURIX/Fee')) and not(contains(text(),'/AURIX/Fls')) and not(contains(text(),'/AURIX/Gpt')) and not(contains(text(),'/AURIX/Icu')) and not(contains(text(),'/AURIX/Irq')) and not(contains(text(),'/AURIX/Mcu')) and not(contains(text(),'/AURIX/Port')) and not(contains(text(),'/AURIX/Pwm')) and not(contains(text(),'/AURIX/Spi')) and not(contains(text(),'/AURIX/Uart')) and not(contains(text(),'/AURIX/I2c'))and not(contains(text(),'/AURIX/Wdg'))]]"/>
	<!-- ##### MODULE-REFS will not be removed but are ignored by Tresos ##### -->
	<!--<xsl:template match="*[local-name()='MODULE-REFS' and *[local-name()='MODULE-REF' and contains(text(),'/MICROSAR/')]]"/>-->
	<!--
	-->
	<!-- ##### Template to copy all other nodes (with attributes) ##### -->
	<xsl:template match="*" priority="0" name="copy_cat">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:apply-templates/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!-- ########## The few following lines are necessary to adapt the MICROSAR Dem to Freescales Dem-Stub ########## -->
	<!-- ##### 'Rename MICROSAR-Dem to /$PluginName$/Dem ##### -->
	<xsl:template match="*[local-name()='DEFINITION-REF' and contains(., '/Dem')]" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>/</xsl:text>
			<xsl:value-of select="$PluginNameDem"/>
			<xsl:text>/Dem</xsl:text>
			<xsl:value-of select="substring-after(., '/Dem')"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
	<!-- ########## The few following lines are necessary to adapt the MICROSAR EcuM to Freescales EcuM-Stub ########## -->
	<!-- ##### 'Rename MICROSAR-EcuM to /$PluginName$/EcuM ##### -->
	<xsl:template match="*[local-name()='DEFINITION-REF' and contains(., '/EcuM')]" priority="1">
		<xsl:copy>
			<xsl:for-each select="@*">
				<xsl:attribute name="{local-name(.)}"><xsl:value-of select="."/></xsl:attribute>
			</xsl:for-each>
			<xsl:text>/</xsl:text>
			<xsl:value-of select="$PluginNameEcum"/>
			<xsl:text>/EcuM</xsl:text>
			<xsl:value-of select="substring-after(., '/EcuM')"/>
		</xsl:copy>
	</xsl:template>
	<!--
	-->
  <!-- ##### 'Delete' 'McuResetReasonConf' containers of Infineon Mcu to prevent warnings at generation process ##### -->
  <!--<xsl:template match="*[local-name()='ECUC-CONTAINER-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/McuResetReasonConf')]]" priority="2"/>-->
  <!--
  -->
  <!-- ##### 'Delete' identifiers and containers of Vector Dem which are non standard parameters in ASR4.0 ##### -->
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemFreezeFrameRecordUpdate')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemFreezeFrameRecordTrigger')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemUdsDTC')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemNvRamBlockIdType')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemNvRamBlockIdIndex')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemImmediateNvStorageSupport')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemMultipleTripSupport')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemSeveritySupport')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemTriggerDtcStatusChangedCallback')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemTriggerEventDataChangedCallback')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemTriggerEventStatusChangedCallback')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemTriggerGlobalEventDataChangedCallback')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemTriggerGlobalEventStatusChangedCallback')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemUseDefensiveBehavior')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemUseNvm')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemUseRte')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemStatusBitHandlingTestFailedSinceLastClear')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/DemOperationCycleProcessing')]]" priority="2"/>
  <!--
  -->
  <!-- ##### 'Delete' identifiers and containers of Vector EcuM which are non standard parameters in ASR4.0 ##### -->
  <xsl:template match="*[local-name()='ECUC-REFERENCE-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/EcuMNormalMcuModeRef')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-REFERENCE-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/EcuMDefaultResetModeRef')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-NUMERICAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/EcuMProductionError')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-REFERENCE-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/ECUM_E_IMPROPER_CALLER')]]" priority="2"/>
  <xsl:template match="*[local-name()='ECUC-TEXTUAL-PARAM-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/EcuMAdditionalIncludes')]]" priority="2"/>
  <!--
  -->
  <xsl:template match="*[local-name()='ECUC-CONTAINER-VALUE' and ./*[local-name()='DEFINITION-REF' and contains(., '/VectorCommonData')]]" priority="2"/>
</xsl:stylesheet>
