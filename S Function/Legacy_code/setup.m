massstruct = legacy_code('initialize');
massstruct.SFunctionName = 'mass';
massstruct.SourceFiles = {'massc.cpp'};
massstruct.HeaderFiles = {'massc.h'};
massstruct.OutputFcnSpec =  'void mass(double u1, double p1, double p2, double p3, double p4, double y1[1], double y2[1])';
pidstruct  = legacy_code('initialize');
pidstruct.SFunctionName = 'PID1';
pidstruct.SourceFiles = {'PIDC.cpp'};
pidstruct.HeaderFiles={'PIDC.h'};
pidstruct.OutputFcnSpec = 'double y1 = pid(double u1, double p1, double p2, double p3)';
legacy_code('sfcn_cmex_generate',massstruct);
legacy_code('compile',massstruct);
legacy_code('sfcn_cmex_generate',pidstruct);
legacy_code('compile',pidstruct);

